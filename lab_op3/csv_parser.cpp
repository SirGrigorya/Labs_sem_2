#include "csv_parser.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_LINE_LENGTH 1024
#define CSV_FIELDS_COUNT 7

bool parse_csv_line(const char* line, DataEntry* entry) {
    bool success = false;

    if (line && entry) {
        size_t line_length = strlen(line);
        if (line_length >= MAX_LINE_LENGTH) {
            success = false;
        } else {
            char* line_copy = (char*)malloc((line_length + 1) * sizeof(char));
            if (line_copy) {
                strcpy(line_copy, line);

                char* token = strtok(line_copy, ",");
                int field_index = 0;

                while (token && field_index < CSV_FIELDS_COUNT) {
                    if (field_index == 0) {
                        entry->year = atoi(token);
                    } else if (field_index == 1) {
                        strncpy(entry->region, token, MAX_REGION_LENGTH);
                        entry->region[MAX_REGION_LENGTH - 1] = '\0';
                    } else if (field_index == 2) {
                        entry->natural_population_growth = strtof(token, NULL);
                    } else if (field_index == 3) {
                        entry->birth_rate = strtof(token, NULL);
                    } else if (field_index == 4) {
                        entry->death_rate = strtof(token, NULL);
                    } else if (field_index == 5) {
                        entry->general_demographic_weight = strtof(token, NULL);
                    } else if (field_index == 6) {
                        entry->urbanization = strtof(token, NULL);
                    }

                    token = strtok(NULL, ",");
                    field_index++;
                }

                if (field_index == CSV_FIELDS_COUNT) {
                    success = true;
                }

                free(line_copy);
            }
        }
    }

    return success;
}

