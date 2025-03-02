#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>

char *allocateMemory(size_t size);
void deallocateMemory(char *ptr);

#endif // MEMORY_H
