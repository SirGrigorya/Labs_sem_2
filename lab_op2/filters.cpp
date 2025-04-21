#include "filters.h"
#include <string.h>

bool is_valid_entry(const DataEntry* entry) {
    bool result = false;

    if (entry) {
        if (strlen(entry->region) > 0 && entry->year > 0) {
            result = true;
        }
    }

    return result;
}

bool is_region_match(const DataEntry* entry, const char* region) {
    bool result = false;

    if (entry) {
        if (!region || strlen(region) == 0) {
            result = true;
        } else {
            result = strcmp(entry->region, region) == 0;
        }
    }

    return result;
}
