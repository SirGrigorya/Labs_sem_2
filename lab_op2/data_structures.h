#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <stdbool.h>

#define MAX_REGION_LENGTH 128

typedef struct {
    int year;
    char region[MAX_REGION_LENGTH];
    float natural_population_growth;
    float birth_rate;
    float death_rate;
    float general_demographic_weight;
    float urbanization;
} DataEntry;

typedef struct {
    DataEntry* entries;
    int size;
    int capacity;
} DataArray;

typedef struct {
    DataArray* array;
    int current_index;
} DataIterator;

void init_data_array(DataArray* array);
void free_data_array(DataArray* array);
bool add_data_entry(DataArray* array, DataEntry entry);

void init_iterator(DataIterator* iterator, DataArray* array);
bool has_next(DataIterator* iterator);
DataEntry* next(DataIterator* iterator);

#endif // DATA_STRUCTURES_H
