#include "logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

List* create_list() {
    List* list = (List*)malloc(sizeof(List));
    list->head = list->tail = NULL;
    return list;
}

void free_list(List* list) {
    Node* current = list->head;
    while (current) {
        Node* next = current->next;
        free(current->data.region);
        free(current);
        current = next;
    }
    free(list);
}

void append_to_list(List* list, const DemographicData* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data.year = data->year;
    node->data.region = strdup(data->region);
    node->data.natural_population_growth = data->natural_population_growth;
    node->data.birth_rate = data->birth_rate;
    node->data.death_rate = data->death_rate;
    node->data.general_demographic_weight = data->general_demographic_weight;
    node->data.urbanization = data->urbanization;
    node->next = NULL;

    if (!list->head) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
}

int parse_csv(const char* filename, List* list, int* totalRows, int* errorRows) {
    FILE* file = fopen(filename, "r");
    if (!file) return -1;

    char line[1024];
    *totalRows = *errorRows = 0;
    fgets(line, sizeof(line), file); // Skip header

    while (fgets(line, sizeof(line), file)) {
        (*totalRows)++;
        DemographicData data;
        int column = 0, error = 0;
        char* token = strtok(line, ",\n");

        while (token && column < 7) {
            if (column == 0) {
                error |= sscanf(token, "%d", &data.year) != 1;
            } else if (column == 1) {
                data.region = strdup(token);
            } else if (column == 2) {
                error |= sscanf(token, "%lf", &data.natural_population_growth) != 1;
            } else if (column == 3) {
                error |= sscanf(token, "%lf", &data.birth_rate) != 1;
            } else if (column == 4) {
                error |= sscanf(token, "%lf", &data.death_rate) != 1;
            } else if (column == 5) {
                error |= sscanf(token, "%lf", &data.general_demographic_weight) != 1;
            } else if (column == 6) {
                error |= sscanf(token, "%lf", &data.urbanization) != 1;
            }
            token = strtok(NULL, ",\n");
            column++;
        }

        if (column != 7 || error) {
            (*errorRows)++;
            if (column >= 2) free(data.region);
        } else {
            append_to_list(list, &data);
        }
    }

    fclose(file);
    return 0;
}

List* filter_by_region(const List* list, const char* region) {
    List* filtered = create_list();
    for (Node* node = list->head; node; node = node->next) {
        if (strcmp(node->data.region, region) == 0) {
            append_to_list(filtered, &node->data);
        }
    }
    return filtered;
}

Iterator get_iterator(const List* list) {
    Iterator it = {list->head};
    return it;
}

DemographicData* next(Iterator* it) {
    if (!it->current) return NULL;
    DemographicData* data = &it->current->data;
    it->current = it->current->next;
    return data;
}

static int compare(const void* a, const void* b) {
    return (*(double*)a > *(double*)b) ? 1 : -1;
}

static double* get_values(const List* list, int column, int* count) {
    *count = 0;
    for (Node* node = list->head; node; node = node->next) (*count)++;
    double* values = (double*)malloc(*count * sizeof(double));
    int i = 0;
    for (Node* node = list->head; node; node = node->next, i++) {
        if (column == 1) {
            values[i] = node->data.natural_population_growth;
        } else if (column == 2) {
            values[i] = node->data.birth_rate;
        } else if (column == 3) {
            values[i] = node->data.death_rate;
        } else if (column == 4) {
            values[i] = node->data.general_demographic_weight;
        } else if (column == 5) {
            values[i] = node->data.urbanization;
        }
    }
    qsort(values, *count, sizeof(double), compare);
    return values;
}

double calculate_min(const List* list, int column) {
    int count;
    double* values = get_values(list, column, &count);
    double min = count ? values[0] : NAN;
    free(values);
    return min;
}

double calculate_max(const List* list, int column) {
    int count;
    double* values = get_values(list, column, &count);
    double max = count ? values[count-1] : NAN;
    free(values);
    return max;
}

double calculate_median(const List* list, int column) {
    int count;
    double* values = get_values(list, column, &count);
    if (!count) {
        free(values);
        return NAN;
    }
    double median;
    if (count % 2) {
        median = values[count/2];
    } else {
        median = (values[count/2 - 1] + values[count/2])/2;
    }
    free(values);
    return median;
}
