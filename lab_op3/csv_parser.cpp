#include "csv_parser.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_LINE_LENGTH 1024
#define CSV_FIELDS_COUNT 7

bool is_valid_year(const char* token, int* year) {
    bool result = false;
    char* endptr = NULL;
    long value = strtol(token, &endptr, 10);

    if (endptr && *endptr == '\0') {
        *year = (int)value;
        result = true;
    }

    return result;
}

void copy_region(char* dest, const char* src) {
    if (dest && src) {
        strncpy(dest, src, MAX_REGION_LENGTH);
        dest[MAX_REGION_LENGTH - 1] = '\0';
    }
}

bool parse_field(DataEntry* entry, const char* token, int field_index) {
    bool result = false;

    if (entry && token) {
        if (field_index == 0) {
            int year = 0;
            if (is_valid_year(token, &year)) {
                entry->year = year;
                result = true;
            }
        } else if (field_index == 1) {
            copy_region(entry->region, token);
            result = true;
        } else if (field_index == 2) {
            entry->natural_population_growth = strtof(token, NULL);
            result = true;
        } else if (field_index == 3) {
            entry->birth_rate = strtof(token, NULL);
            result = true;
        } else if (field_index == 4) {
            entry->death_rate = strtof(token, NULL);
            result = true;
        } else if (field_index == 5) {
            entry->general_demographic_weight = strtof(token, NULL);
            result = true;
        } else if (field_index == 6) {
            entry->urbanization = strtof(token, NULL);
            result = true;
        }
    }

    return result;
}

bool parse_csv_line(const char* line, DataEntry* entry) {
    bool result = false;

    if (line && entry) {
        size_t line_length = strlen(line);
        if (line_length < MAX_LINE_LENGTH) {
            char* line_copy = (char*)malloc((line_length + 1) * sizeof(char));
            if (line_copy) {
                strcpy(line_copy, line);

                char* token = strtok(line_copy, ",");
                int field_index = 0;
                bool valid = true;

                while (token && field_index < CSV_FIELDS_COUNT && valid) {
                    if (!parse_field(entry, token, field_index)) {
                        valid = false;
                    }
                    token = strtok(NULL, ",");
                    field_index++;
                }

                if (valid && field_index == CSV_FIELDS_COUNT && token == NULL) {
                    result = true;
                }

                free(line_copy);
            }
        }
    }

    return result;
}
