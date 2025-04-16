#include "statistics.h"
#include "data_structures.h"
#include "constants.h"
#include <stdlib.h>

static int compare_doubles(const void* a, const void* b) {
    int result = COMPARE_EQUAL;
    double diff = *(const double*)a - *(const double*)b;

    if (diff > 0.0) {
        result = COMPARE_GREATER;
    }
    else if (diff < 0.0) {
        result = COMPARE_LESS;
    }

    return result;
}

static double* get_column_values(const List* list, int column, int* count) {
    double* values = NULL;
    *count = 0;

    if (list && column >= COLUMN_NATURAL_GROWTH && column <= COLUMN_URBANIZATION) {
        Node* node = list->head;
        int size = 0;

        while (node) {
            size++;
            node = node->next;
        }

        if (size > 0) {
            values = (double*)malloc(size * sizeof(double));
            if (values) {
                node = list->head;
                int i = 0;
                while (node) {
                    if (column == COLUMN_NATURAL_GROWTH) {
                        values[i] = node->data.natural_population_growth;
                    }
                    else if (column == COLUMN_BIRTH_RATE) {
                        values[i] = node->data.birth_rate;
                    }
                    else if (column == COLUMN_DEATH_RATE) {
                        values[i] = node->data.death_rate;
                    }
                    else if (column == COLUMN_DEMO_WEIGHT) {
                        values[i] = node->data.general_demographic_weight;
                    }
                    else if (column == COLUMN_URBANIZATION) {
                        values[i] = node->data.urbanization;
                    }

                    i++;
                    node = node->next;
                }
                qsort(values, size, sizeof(double), compare_doubles);
                *count = size;
            }
        }
    }
    return values;
}

double calculate_min(const List* list, int column) {
    double result = NAN;
    int count = 0;
    double* values = get_column_values(list, column, &count);

    if (values && count > 0) {
        result = values[0];
    }
    free(values);
    return result;
}

double calculate_max(const List* list, int column) {
    double result = NAN;
    int count = 0;
    double* values = get_column_values(list, column, &count);

    if (values && count > 0) {
        result = values[count - 1];
    }
    free(values);
    return result;
}

double calculate_median(const List* list, int column) {
    double result = NAN;
    int count = 0;
    double* values = get_column_values(list, column, &count);

    if (values && count > 0) {
        int middle = count / 2;
        result = count % 2 ? values[middle] : (values[middle - 1] + values[middle]) / 2.0;
    }
    free(values);
    return result;
}
