#include "logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LIST_INITIALIZER {NULL, NULL}
#define CSV_LINE_BUFFER_SIZE 1024
#define CSV_COLUMNS_COUNT 7
#define CSV_HEADER_SKIP 1
#define COLUMN_YEAR 0
#define COLUMN_REGION 1
#define COLUMN_NATURAL_GROWTH 2
#define COLUMN_BIRTH_RATE 3
#define COLUMN_DEATH_RATE 4
#define COLUMN_DEMO_WEIGHT 5
#define COLUMN_URBANIZATION 6
#define PARSE_SUCCESS 0
#define PARSE_ERROR -1
#define COMPARE_LESS -1
#define COMPARE_EQUAL 0
#define COMPARE_GREATER 1

List* create_list() {
    List* list = (List*)malloc(sizeof(List));
    if (list) {
        list->head = NULL;
        list->tail = NULL;
    }
    return list;
}

void free_list(List* list) {
    Node* current = NULL;
    Node* next = NULL;
    int result = 0;

    if (!list) {
        return;
    }

    current = list->head;
    while (current) {
        next = current->next;
        free(current->data.region);
        free(current);
        current = next;
    }
    free(list);
}

void append_to_list(List* list, const DemographicData* data) {
    Node* node = NULL;

    if (!list || !data) {
        return;
    }

    node = (Node*)malloc(sizeof(Node));
    if (!node) {
        return;
    }

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
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

int parse_csv(const char* filename, List* list, int* totalRows, int* errorRows) {
    FILE* file = NULL;
    char line[CSV_LINE_BUFFER_SIZE];
    int result = PARSE_SUCCESS;

    if (!filename || !list || !totalRows || !errorRows) {
        return PARSE_ERROR;
    }

    file = fopen(filename, "r");
    if (!file) {
        return PARSE_ERROR;
    }

    *totalRows = 0;
    *errorRows = 0;

    if (!fgets(line, sizeof(line), file)) {
        fclose(file);
        return PARSE_ERROR;
    }

    while (fgets(line, sizeof(line), file)) {
        DemographicData data = {0};
        char* token = NULL;
        int column = 0;
        int error = 0;

        (*totalRows)++;
        token = strtok(line, ",\n");

        while (token && column < CSV_COLUMNS_COUNT) {
            if (column == COLUMN_YEAR) {
                error |= (sscanf(token, "%d", &data.year) != 1);
            } else if (column == COLUMN_REGION) {
                data.region = strdup(token);
                error |= (data.region == NULL);
            } else if (column == COLUMN_NATURAL_GROWTH) {
                error |= (sscanf(token, "%lf", &data.natural_population_growth) != 1);
            } else if (column == COLUMN_BIRTH_RATE) {
                error |= (sscanf(token, "%lf", &data.birth_rate) != 1);
            } else if (column == COLUMN_DEATH_RATE) {
                error |= (sscanf(token, "%lf", &data.death_rate) != 1);
            } else if (column == COLUMN_DEMO_WEIGHT) {
                error |= (sscanf(token, "%lf", &data.general_demographic_weight) != 1);
            } else if (column == COLUMN_URBANIZATION) {
                error |= (sscanf(token, "%lf", &data.urbanization) != 1);
            }

            token = strtok(NULL, ",\n");
            column++;
        }

        if (column != CSV_COLUMNS_COUNT || error) {
            (*errorRows)++;
            if (column > COLUMN_REGION && data.region) {
                free(data.region);
            }
        } else {
            append_to_list(list, &data);
            free(data.region);
        }
    }

    fclose(file);
    return result;
}

List* filter_by_region(const List* list, const char* region) {
    List* filtered = NULL;
    Node* node = NULL;

    if (!list || !region) {
        return NULL;
    }

    filtered = create_list();
    if (!filtered) {
        return NULL;
    }

    node = list->head;
    while (node) {
        if (strcmp(node->data.region, region) == COMPARE_EQUAL) {
            append_to_list(filtered, &node->data);
        }
        node = node->next;
    }

    return filtered;
}

Iterator get_iterator(const List* list) {
    Iterator it = {NULL};

    if (list) {
        it.current = list->head;
    }

    return it;
}

DemographicData* next(Iterator* it) {
    DemographicData* result = NULL;

    if (it && it->current) {
        result = &it->current->data;
        it->current = it->current->next;
    }

    return result;
}

static int compare_doubles(const void* a, const void* b) {
    double diff = *(const double*)a - *(const double*)b;
    return (diff > 0.0) ? COMPARE_GREATER :
               (diff < 0.0) ? COMPARE_LESS : COMPARE_EQUAL;
}

static double* get_column_values(const List* list, int column, int* count) {
    double* values = NULL;
    Node* node = NULL;
    int i = 0;

    *count = 0;
    if (!list || column < COLUMN_NATURAL_GROWTH || column > COLUMN_URBANIZATION) {
        return NULL;
    }

    node = list->head;
    while (node) {
        (*count)++;
        node = node->next;
    }

    if (*count == 0) {
        return NULL;
    }

    values = (double*)malloc(*count * sizeof(double));
    if (!values) {
        return NULL;
    }

    node = list->head;
    while (node) {
        if (column == COLUMN_NATURAL_GROWTH) {
            values[i] = node->data.natural_population_growth;
        } else if (column == COLUMN_BIRTH_RATE) {
            values[i] = node->data.birth_rate;
        } else if (column == COLUMN_DEATH_RATE) {
            values[i] = node->data.death_rate;
        } else if (column == COLUMN_DEMO_WEIGHT) {
            values[i] = node->data.general_demographic_weight;
        } else if (column == COLUMN_URBANIZATION) {
            values[i] = node->data.urbanization;
        }
        i++;
        node = node->next;
    }

    qsort(values, *count, sizeof(double), compare_doubles);
    return values;
}

double calculate_min(const List* list, int column) {
    int count = 0;
    double* values = NULL;
    double result = NAN;

    values = get_column_values(list, column, &count);
    if (values && count > 0) {
        result = values[0];
    }

    if (values) {
        free(values);
    }

    return result;
}

double calculate_max(const List* list, int column) {
    int count = 0;
    double* values = NULL;
    double result = NAN;

    values = get_column_values(list, column, &count);
    if (values && count > 0) {
        result = values[count - 1];
    }

    if (values) {
        free(values);
    }

    return result;
}

double calculate_median(const List* list, int column) {
    int count = 0;
    double* values = NULL;
    double result = NAN;

    values = get_column_values(list, column, &count);
    if (!values || count == 0) {
        if (values) free(values);
        return result;
    }

    if (count % 2) {
        result = values[count / 2];
    } else {
        result = (values[count / 2 - 1] + values[count / 2]) / 2.0;
    }

    free(values);
    return result;
}
