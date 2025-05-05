#ifndef DATA_ITERATOR_H
#define DATA_ITERATOR_H

#include "data_structures.h"
#include <stdbool.h>

typedef struct {
    DataArray* array;
    int current_index;
} DataIterator;

void init_iterator(DataIterator* iterator, DataArray* array);
bool has_next(DataIterator* iterator);
DataEntry* next(DataIterator* iterator);

#endif // DATA_ITERATOR_H
