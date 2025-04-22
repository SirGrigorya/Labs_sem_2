#include "data_structures.h"
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 32
#define CAPACITY_GROWTH_FACTOR 2

void init_data_array(DataArray* array) {
    array->entries = (DataEntry*)malloc(INITIAL_CAPACITY * sizeof(DataEntry));
    array->size = 0;
    array->capacity = INITIAL_CAPACITY;
}

void free_data_array(DataArray* array) {
    if (array->entries) {
        free(array->entries);
        array->entries = NULL;
    }
    array->size = 0;
    array->capacity = 0;
}

bool add_data_entry(DataArray* array, DataEntry entry) {
    bool result = true;

    if (array->size >= array->capacity) {
        int new_capacity = array->capacity * CAPACITY_GROWTH_FACTOR;
        DataEntry* new_entries = (DataEntry*)realloc(array->entries, new_capacity * sizeof(DataEntry));
        if (new_entries) {
            array->entries = new_entries;
            array->capacity = new_capacity;
        } else {
            result = false;
        }
    }

    if (result) {
        array->entries[array->size++] = entry;
    }

    return result;
}
