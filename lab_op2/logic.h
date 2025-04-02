#ifndef LOGIC_H
#define LOGIC_H

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
int parse_csv(const char* filename, List* list, int* totalRows, int* errorRows);
List* filter_by_region(const List* list, const char* region);
Iterator get_iterator(const List* list);
DemographicData* next(Iterator* it);
double calculate_min(const List* list, int column);
double calculate_max(const List* list, int column);
double calculate_median(const List* list, int column);

#endif // LOGIC_H
