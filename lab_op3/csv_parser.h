#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <stdbool.h>
#include "data_structures.h"

bool parse_csv_line(const char* line, DataEntry* entry);

static bool parse_field(DataEntry* entry, const char* token, int field_index);
static bool is_valid_year(const char* token, int* year);
static void copy_region(char* dest, const char* src);

#endif // CSV_PARSER_H
