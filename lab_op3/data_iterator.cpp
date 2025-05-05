#include "data_iterator.h"
#include <cstddef>

void init_iterator(DataIterator* iterator, DataArray* array) {
    iterator->array = array;
    iterator->current_index = 0;
}

bool has_next(DataIterator* iterator) {
    return iterator->current_index < iterator->array->size;
}

DataEntry* next(DataIterator* iterator) {
    DataEntry* result = NULL;
    if (iterator->current_index < iterator->array->size) {
        result = &iterator->array->entries[iterator->current_index++];
    }
    return result;
}
