#include "filters.h"
#include "data_structures.h"
#include <string.h>

List* filter_by_region(const List* list, const char* region) {
    List* filtered = NULL;

    if (list && region) {
        filtered = create_list();
        if (filtered) {
            Node* node = list->head;
            while (node) {
                if (strcmp(node->data.region, region) == 0) {
                    append_to_list(filtered, &node->data);
                }
                node = node->next;
            }
        }
    }
    return filtered;
}
