#ifndef FILTERS_H
#define FILTERS_H

#include <stdbool.h>
#include "data_structures.h"

bool is_valid_entry(const DataEntry* entry);

bool is_region_match(const DataEntry* entry, const char* region);

#endif // FILTERS_H
