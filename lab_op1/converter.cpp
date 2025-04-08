#include "converter.h"
#include "errors.h"
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#define MAX_BIN_LENGTH      32
#define MAX_DEC_LENGTH      12
#define MAX_HEX_LENGTH      8
#define BIT_LENGTH          32
#define HEX_NEGATIVE_ONE    "FFFFFFFF"
#define BIN_NEGATIVE_ONE    "11111111111111111111111111111111"
#define HEX_FORMAT          "%08lX"
#define DEC_FORMAT          "%ld"
#define HEX_SIGNED_FORMAT   "%08X"
#define DEC 10
#define BIN 2
#define HEX 16

static bool isBinaryString(const char *str) {
    bool valid = true;
    for (size_t i = 0; str[i] && valid; i++) {
        valid = (str[i] == '0' || str[i] == '1');
    }
    return valid;
}

static bool isDecimalString(const char *str) {
    bool valid = true;
    size_t start = 0;

    if (str[0] == '-') start = 1;

    for (size_t i = start; str[i] && valid; i++) {
        valid = isdigit(str[i]);
    }
    return valid;
}

static bool isHexadecimalString(const char *str) {
    bool valid = true;
    for (size_t i = 0; str[i] && valid; i++) {
        valid = isxdigit(str[i]);
    }
    return valid;
}

bool isValidInput(const char *input, int base) {
    bool valid = false;

    if (input && *input) {
        const size_t len = strlen(input);

        if (base == BIN) {
            valid = (len <= MAX_BIN_LENGTH) && isBinaryString(input);
        }
        else if (base == DEC) {
            valid = (len <= MAX_DEC_LENGTH) && isDecimalString(input);
        }
        else if (base == HEX) {
            valid = (len <= MAX_HEX_LENGTH) && isHexadecimalString(input);
        }
    }

    return valid;
}

static bool handleSpecialCases(const char *input, int fromBase, int toBase, char *result) {
    bool handled = false;

    if (fromBase == HEX && strcmp(input, HEX_NEGATIVE_ONE) == 0) {
        if (toBase == DEC) {
            strcpy(result, "-1");
            handled = true;
        }
        else if (toBase == BIN) {
            strcpy(result, BIN_NEGATIVE_ONE);
            handled = true;
        }
    }
    else if (fromBase == BIN && strlen(input) == BIT_LENGTH) {
        bool allOnes = true;
        for (int i = 0; i < BIT_LENGTH; i++) {
            if (input[i] != '1') {
                allOnes = false;
                break;
            }
        }
        if (allOnes) {
            if (toBase == DEC) {
                strcpy(result, "-1");
                handled = true;
            }
            else if (toBase == HEX) {
                strcpy(result, HEX_NEGATIVE_ONE);
                handled = true;
            }
        }
    }

    return handled;
}

static void convertUnsignedNumber(unsigned long number, int toBase, char *result) {
    if (toBase == BIN) {
        for (int i = BIT_LENGTH - 1; i >= 0; i--) {
            result[BIT_LENGTH - 1 - i] = (number & (1UL << i)) ? '1' : '0';
        }
        result[BIT_LENGTH] = '\0';
    }
    else if (toBase == DEC) {
        snprintf(result, MAX_DEC_LENGTH + 1, DEC_FORMAT, number);
    }
    else if (toBase == HEX) {
        snprintf(result, MAX_HEX_LENGTH + 1, HEX_FORMAT, number);
    }
}


static const char *validateInputs(const char *input, char *result, int fromBase) {
    const char *error = NULL;

    if (input == NULL || result == NULL) {
        error = getErrorMessage(NullPointer);
    }
    else if (!isValidInput(input, fromBase)) {
        error = getErrorMessage(InvalidInput);
    }

    return error;
}

static const char *parseNumber(
    const char *input,
    int fromBase,
    unsigned long *number,
    char **endPtr
    ) {
    const char *error = NULL;

    errno = 0;
    *number = strtoul(input, endPtr, fromBase);

    if (**endPtr != '\0') {
        error = getErrorMessage(InvalidInput);
    }
    else if (errno == ERANGE) {
        error = getErrorMessage(OutOfRange);
    }

    return error;
}

static const char *handleHexOverflow(
    unsigned long number,
    int toBase,
    char *result
    ) {
    const int signedNumber = (int)(number - UINT_MAX - 1);
    const char *error = getErrorMessage(InvalidBase); // default error

    if (toBase == DEC) {
        snprintf(result, MAX_DEC_LENGTH + 1, "%d", signedNumber);
        error = NULL;
    }
    else if (toBase == BIN) {
        convertUnsignedNumber((unsigned int)signedNumber, toBase, result);
        error = NULL;
    }
    else if (toBase == HEX) {
        snprintf(result, MAX_HEX_LENGTH + 1, HEX_SIGNED_FORMAT,
                 (unsigned int)signedNumber);
        error = NULL;
    }

    return error;
}

static const char *performConversion(
    unsigned long number,
    int toBase,
    char *result
    ) {
    const char *error = NULL;
    if (toBase < BIN || toBase > HEX) {
        error = getErrorMessage(InvalidBase);
    } else {
        convertUnsignedNumber(number, toBase, result);
    }
    return error;
}

static bool tryHandleSpecialCases(
    const char *input,
    int fromBase,
    int toBase,
    char *result
    ) {
    bool handled = false;
    if (!handled && fromBase == HEX && strcmp(input, HEX_NEGATIVE_ONE) == 0) {
        if (toBase == 10) {
            strcpy(result, "-1");
            handled = true;
        }
        else if (toBase == BIN) {
            strcpy(result, BIN_NEGATIVE_ONE);
            handled = true;
        }
    }
    if (!handled && fromBase == BIN && strlen(input) == BIT_LENGTH) {
        bool all_ones = true;

        for (int i = 0; i < BIT_LENGTH; i++) {
            if (input[i] != '1') {
                all_ones = false;
                break;
            }
        }
        if (all_ones) {
            if (toBase == DEC) {
                strcpy(result, "-1");
                handled = true;
            }
            else if (toBase == HEX) {
                strcpy(result, HEX_NEGATIVE_ONE);
                handled = true;
            }
        }
    }
    return handled;
}

const char *convertNumber(const char *input, int fromBase, int toBase, char *result) {
    const char *error = NULL;
    unsigned long number = 0;
    char *endPtr = NULL;
    bool specialCaseHandled = false;
    error = validateInputs(input, result, fromBase);
    if (!error) {
        specialCaseHandled = tryHandleSpecialCases(input, fromBase, toBase, result);
        if (!specialCaseHandled) {
            error = parseNumber(input, fromBase, &number, &endPtr);

            if (!error) {
                if (fromBase == HEX && number > INT_MAX) {
                    error = handleHexOverflow(number, toBase, result);
                }
                else {
                    error = performConversion(number, toBase, result);
                }
            }
        }
    }
    return error;
}
