#include "statistics.h"
#include "filters.h"
#include <stdlib.h>

#define MAX_VALUES       10000
#define COLUMN_MIN_INDEX 1
#define COLUMN_MAX_INDEX 5
#define FIELD_COUNT      5

static int float_compare(const void* a, const void* b) {
    float fa = *(const float*)a;
    float fb = *(const float*)b;
    return (fa > fb) - (fa < fb);
}

static bool get_column_value(const DataEntry* entry, int index, float* out) {
    bool success = false;

    if (entry && out && index >= COLUMN_MIN_INDEX && index <= COLUMN_MAX_INDEX) {
        const float* fields[FIELD_COUNT] = {
            &entry->natural_population_growth,
            &entry->birth_rate,
            &entry->death_rate,
            &entry->general_demographic_weight,
            &entry->urbanization
        };

        *out = *fields[index - 1];
        success = true;
    }

    return success;
}

bool calculate_statistics(
    const DataArray* array,
    const char* region,
    int column_index,
    StatisticsResult* stats
    ) {
    bool result = false;

    if (array && stats &&
        column_index >= COLUMN_MIN_INDEX &&
        column_index <= COLUMN_MAX_INDEX)
    {
        float* values = (float*)malloc(sizeof(float) * MAX_VALUES);
        if (values) {
            int count = 0;

            for (int i = 0; i < array->size && count < MAX_VALUES; ++i) {
                const DataEntry* entry = &array->entries[i];

                if (is_valid_entry(entry)) {
                    if (region == nullptr || region[0] == '\0' || is_region_match(entry, region)) {
                        float value;
                        if (get_column_value(entry, column_index, &value)) {
                            values[count++] = value;
                        }
                    }
                }
            }

            if (count > 0) {
                qsort(values, count, sizeof(float), float_compare);

                stats->min = values[0];
                stats->max = values[count - 1];

                if (count % 2 == 1) {
                    stats->median = values[count / 2];
                } else {
                    stats->median = (values[count / 2 - 1] + values[count / 2]) / 2.0f;
                }

                result = true;
            }

            free(values);
        }
    }

    return result;
}
