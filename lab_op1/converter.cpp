#include "converter.h"
#include "errors.h"
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <climits>
#include <cerrno>

bool isValidInput(const char *input, int base) {
    if (base == 2) {
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] != '0' && input[i] != '1') return false;
        }
    } else if (base == 10) {
        for (int i = 0; input[i] != '\0'; i++) {
            if (!isdigit(input[i]) && !(i == 0 && input[i] == '-')) return false;
        }
    } else if (base == 16) {
        for (int i = 0; input[i] != '\0'; i++) {
            if (!isxdigit(input[i])) return false;
        }
    }
    return true;
}

const char *convertNumber(const char *input, int fromBase, int toBase, char *result) {
    // Валидация ввода
    if (!isValidInput(input, fromBase)) {
        return getErrorMessage(InvalidInput);
    }

    // Сброс errno перед преобразованием
    errno = 0;
    char *endPtr;
    long int number = strtol(input, &endPtr, fromBase);

    // Проверка на неконвертируемые символы
    if (*endPtr != '\0') {
        return getErrorMessage(InvalidInput);
    }

    // Проверка на переполнение при преобразовании
    if (errno == ERANGE) {
        return getErrorMessage(OutOfRange);
    }

    // Явная проверка диапазона для 4-байтового int
    if (number < INT_MIN || number > INT_MAX) {
        return getErrorMessage(OutOfRange);
    }

    // Конвертация числа
    int value = (int)number;
    if (toBase == 2) {
        itoa(value, result, 2);
    } else if (toBase == 10) {
        itoa(value, result, 10);
    } else if (toBase == 16) {
        itoa(value, result, 16);
    }

    return NULL; // Ошибок нет
}
