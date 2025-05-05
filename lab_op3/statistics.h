#ifndef STATISTICS_H
#define STATISTICS_H

#include <stdbool.h>
#include "data_structures.h"

typedef struct {
    float min;
    float max;
    float median;
} StatisticsResult;

bool calculate_statistics(
    const DataArray* array,
    const char* region,
    int column_index,
    StatisticsResult* result
    );

#endif // STATISTICS_H
