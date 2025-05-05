#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <stdbool.h>
#include "data_structures.h"

bool parse_csv_line(const char* line, DataEntry* entry);

#endif // CSV_PARSER_H
