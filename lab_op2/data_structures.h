#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

typedef struct {
    int year;
    char* region;
    double natural_population_growth;
    double birth_rate;
    double death_rate;
    double general_demographic_weight;
    double urbanization;
} DemographicData;

typedef struct Node {
    DemographicData data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} List;

typedef struct {
    Node* current;
} Iterator;

List* create_list();
void free_list(List* list);
void append_to_list(List* list, const DemographicData* data);
Iterator get_iterator(const List* list);
DemographicData* next(Iterator* it);

#endif // DATA_STRUCTURES_H
