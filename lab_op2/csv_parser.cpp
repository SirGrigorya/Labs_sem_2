#include "csv_parser.h"
#include "data_structures.h"
#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_csv(const char* filename, List* list, int* totalRows, int* errorRows) {
    FILE* file = NULL;
    char line[CSV_LINE_BUFFER_SIZE];
    int result = PARSE_ERROR;

    if (filename && list && totalRows && errorRows) {
        file = fopen(filename, "r");
        if (file) {
            if (fgets(line, sizeof(line), file)) {
                result = PARSE_SUCCESS;
                *totalRows = 0;
                *errorRows = 0;

                while (fgets(line, sizeof(line), file)) {
                    DemographicData data = {0};
                    char* token = NULL;
                    int column = 0;
                    int error = 0;

                    (*totalRows)++;
                    token = strtok(line, ",\n");

                    while (token && column < CSV_COLUMNS_COUNT) {
                        if (column == COLUMN_YEAR) {
                            error |= (sscanf(token, "%d", &data.year) != 1);
                        }
                        else if (column == COLUMN_REGION) {
                            data.region = strdup(token);
                            error |= (data.region == NULL);
                        }
                        else if (column == COLUMN_NATURAL_GROWTH) {
                            error |= (sscanf(token, "%lf", &data.natural_population_growth) != 1);
                        }
                        else if (column == COLUMN_BIRTH_RATE) {
                            error |= (sscanf(token, "%lf", &data.birth_rate) != 1);
                        }
                        else if (column == COLUMN_DEATH_RATE) {
                            error |= (sscanf(token, "%lf", &data.death_rate) != 1);
                        }
                        else if (column == COLUMN_DEMO_WEIGHT) {
                            error |= (sscanf(token, "%lf", &data.general_demographic_weight) != 1);
                        }
                        else if (column == COLUMN_URBANIZATION) {
                            error |= (sscanf(token, "%lf", &data.urbanization) != 1);
                        }

                        token = strtok(NULL, ",\n");
                        column++;
                    }

                    if (column != CSV_COLUMNS_COUNT || error) {
                        (*errorRows)++;
                        if (column > COLUMN_REGION && data.region) {
                            free(data.region);
                        }
                    } else {
                        append_to_list(list, &data);
                        free(data.region);
                    }
                }
            }
            fclose(file);
        }
    }
    return result;
}
