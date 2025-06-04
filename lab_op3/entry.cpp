#include "entry.h"
#include "csv_parser.h"
#include "filters.h"
#include "statistics.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 512
#define ERROR_MESSAGE_SIZE 256
#define MIN_COLUMN_INDEX 1
#define MAX_COLUMN_INDEX 5

void init_context(AppContext* ctx) {
    if (ctx) {
        ctx->data = (DataArray*)malloc(sizeof(DataArray));
        if (ctx->data) {
            init_data_array(ctx->data);
        }

        ctx->last_error = (char*)malloc(ERROR_MESSAGE_SIZE);
        if (ctx->last_error) {
            ctx->last_error[0] = '\0';
        }

        ctx->total_lines = 0;
        ctx->error_lines = 0;
        ctx->valid_lines = 0;
    }
}

void free_context(AppContext* ctx) {
    if (ctx) {
        if (ctx->data) {
            free_data_array(ctx->data);
            free(ctx->data);
            ctx->data = NULL;
        }

        if (ctx->last_error) {
            free(ctx->last_error);
            ctx->last_error = NULL;
        }
    }
}

bool load_csv_file(AppContext* ctx, const char* filepath) {
    bool success = false;

    if (ctx && ctx->data && ctx->last_error && filepath) {
        FILE* file = fopen(filepath, "r");
        if (file) {
            char* line = (char*)malloc(MAX_LINE_LENGTH);
            if (line) {
                if (fgets(line, MAX_LINE_LENGTH, file)) {
                    while (fgets(line, MAX_LINE_LENGTH, file)) {
                        ctx->total_lines++;
                        line[strcspn(line, "\r\n")] = '\0';

                        DataEntry entry;
                        if (parse_csv_line(line, &entry) && is_valid_entry(&entry)) {
                            if (!add_data_entry(ctx->data, entry)) {
                                snprintf(ctx->last_error, ERROR_MESSAGE_SIZE, "Memory allocation failed.");
                                break;
                            }
                            ctx->valid_lines++;
                        } else {
                            ctx->error_lines++;
                        }
                    }
                    success = true;
                } else {
                    snprintf(ctx->last_error, ERROR_MESSAGE_SIZE, "Empty file.");
                }
                free(line);
            } else {
                snprintf(ctx->last_error, ERROR_MESSAGE_SIZE, "Memory allocation failed.");
            }
            fclose(file);
        } else {
            snprintf(ctx->last_error, ERROR_MESSAGE_SIZE, "Can't open file.");
        }
    }

    return success;
}

bool allocate_series_memory(DataSeries* out_series, size_t count) {
    bool result = true;
    out_series->years = (int*)malloc(sizeof(int) * count);
    out_series->values = (double*)malloc(sizeof(double) * count);

    if (!out_series->years || !out_series->values) {
        result = false;
    }

    return result;
}

bool get_value_by_column_index(int column_index, DataEntry* entry, double* value) {
    bool result = false;

    if (column_index == 1) {
        *value = entry->natural_population_growth;
        result = true;
    } else if (column_index == 2) {
        *value = entry->birth_rate;
        result = true;
    } else if (column_index == 3) {
        *value = entry->death_rate;
        result = true;
    } else if (column_index == 4) {
        *value = entry->general_demographic_weight;
        result = true;
    } else if (column_index == 5) {
        *value = entry->urbanization;
        result = true;
    }

    return result;
}

bool extract_series(const AppContext* ctx, const char* region, int column_index, DataSeries* out_series) {
    bool result = false;

    if (ctx && ctx->data && region && out_series) {
        size_t count = 0;

        for (int i = 0; i < ctx->data->size; ++i) {
            DataEntry* entry = &ctx->data->entries[i];
            if (is_region_match(entry, region)) {
                count++;
            }
        }

        if (count > 0) {
            if (allocate_series_memory(out_series, count)) {
                size_t index = 0;
                bool valid = true;

                for (int i = 0; i < ctx->data->size; ++i) {
                    DataEntry* entry = &ctx->data->entries[i];
                    if (is_region_match(entry, region)) {
                        out_series->years[index] = entry->year;

                        double value = 0;
                        if (get_value_by_column_index(column_index, entry, &value)) {
                            out_series->values[index] = value;
                            index++;
                        } else {
                            valid = false;
                            break;
                        }
                    }
                }

                if (valid) {
                    out_series->size = count;
                    result = true;
                } else {
                    free(out_series->years);
                    free(out_series->values);
                }
            }
        }
    }

    return result;
}

bool calculate_metrics(AppContext* ctx, const char* region, int column_index, StatisticsResult* result) {
    bool success = false;

    if (ctx && ctx->data && ctx->last_error && result) {
        if (column_index >= MIN_COLUMN_INDEX && column_index <= MAX_COLUMN_INDEX) {
            success = calculate_statistics(ctx->data, region, column_index, result);
            if (!success) {
                snprintf(ctx->last_error, ERROR_MESSAGE_SIZE, "Not enough valid data for statistics.");
            }
        } else {
            snprintf(ctx->last_error, ERROR_MESSAGE_SIZE, "Invalid column index.");
        }
    }

    return success;
}
