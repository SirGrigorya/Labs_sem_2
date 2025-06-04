#ifndef ENTRY_H
#define ENTRY_H

#include "data_structures.h"
#include "statistics.h"
#include <cstddef>
#include <stdbool.h>

typedef struct {
    int* years;
    double* values;
    size_t size;
} DataSeries;

typedef struct {
    DataArray* data;
    int total_lines;
    int error_lines;
    int valid_lines;
    char* last_error;
    DataSeries series;
    StatisticsResult stats;
} AppContext;

void init_context(AppContext* ctx);
void free_context(AppContext* ctx);

bool load_csv_file(AppContext* ctx, const char* filepath);

bool extract_series(const AppContext* ctx, const char* region, int column_index, DataSeries* out_series);

bool calculate_metrics(AppContext* ctx, const char* region, int column_index, StatisticsResult* result);

bool allocate_series_memory(DataSeries* out_series, size_t count);

bool get_value_by_column_index(int column_index, DataEntry* entry, double* value);

#endif // ENTRY_H
