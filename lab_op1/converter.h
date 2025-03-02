#ifndef CONVERTER_H
#define CONVERTER_H

#include <stdbool.h>

// Проверка валидности ввода
bool isValidInput(const char *input, int base);

// Проверка диапазона числа
bool isWithinRange(long int number);

// Конвертация числа
const char *convertNumber(const char *input, int fromBase, int toBase, char *result);

#endif // CONVERTER_H
