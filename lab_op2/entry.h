#ifndef ENTRY_H
#define ENTRY_H

#include "data_structures.h"

typedef struct {
    DataArray data;
    int total_lines;
    int error_lines;
    int valid_lines;
    float min;
    float max;
    float median;
    char last_error[256];
} AppContext;

void init_context(AppContext* ctx);
void free_context(AppContext* ctx);

bool load_csv_file(AppContext* ctx, const char* filepath);

bool calculate_metrics(AppContext* ctx, const char* region, int column_index);

#endif // ENTRY_H
