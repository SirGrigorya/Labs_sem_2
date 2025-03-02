#include "memory.h"

char *allocateMemory(size_t size) {
    return (char *)malloc(size);
}

void deallocateMemory(char *ptr) {
    free(ptr);
}
