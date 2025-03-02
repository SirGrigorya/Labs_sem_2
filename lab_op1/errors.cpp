#include "errors.h"

const char *getErrorMessage(ErrorCode code) {
    switch (code) {
    case InvalidInput:
        return "Ошибка: некорректный ввод для выбранной системы счисления.";
    case OutOfRange:
        return "Ошибка: число выходит за пределы диапазона 4-байтового знакового целого числа.";
    default:
        return "";
    }
}
