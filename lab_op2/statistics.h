#ifndef STATISTICS_H
#define STATISTICS_H

#include <stdbool.h>
#include "data_structures.h"

bool calculate_statistics(
    const DataArray* array,
    const char* region,
    int column_index,
    float* min,
    float* max,
    float* median
    );

#endif // STATISTICS_H
