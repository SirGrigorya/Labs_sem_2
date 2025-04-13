#ifndef STATISTICS_H
#define STATISTICS_H

#include "data_structures.h"
#include <math.h>

double calculate_min(const List* list, int column);
double calculate_max(const List* list, int column);
double calculate_median(const List* list, int column);

#endif // STATISTICS_H
