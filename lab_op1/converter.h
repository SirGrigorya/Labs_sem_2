#ifndef CONVERTER_H
#define CONVERTER_H

#include <stdbool.h>

bool isValidInput(const char *input, int base);

bool isWithinRange(long int number);

const char *convertNumber(const char *input, int fromBase, int toBase, char *result);

#endif // CONVERTER_H
