#ifndef ENTRY_H
#define ENTRY_H

#include "data_structures.h"

typedef struct {
    List* all_data;
    List* filtered_data;
    int total_rows;
    int error_rows;
    int valid_rows;
    char error[256];
} Context;

void init_context(Context* ctx);
int load_data(Context* ctx, const char* filename, const char* region);
void calculate_metrics(Context* ctx, int column, double* min, double* max, double* median);
void free_context(Context* ctx);

#endif // ENTRY_H
