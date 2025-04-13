#include "data_structures.h"
#include <stdlib.h>
#include <string.h>

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

    if (list) {
        current = list->head;
        while (current) {
            next = current->next;
            free(current->data.region);
            free(current);
            current = next;
        }
        free(list);
    }
}

void append_to_list(List* list, const DemographicData* data) {
    Node* node = NULL;

    if (list && data) {
        node = (Node*)malloc(sizeof(Node));
        if (node) {
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
    }
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
