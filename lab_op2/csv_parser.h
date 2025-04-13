#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include "data_structures.h"

int parse_csv(const char* filename, List* list, int* totalRows, int* errorRows);

#endif // CSV_PARSER_H
