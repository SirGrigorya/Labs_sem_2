#include "errors.h"

const char *getErrorMessage(ErrorCode code) {
    if (code == InvalidInput) {
        return "Ошибка: некорректный ввод для выбранной системы счисления.";
    } else if (code == OutOfRange) {
        return "Ошибка: число выходит за пределы диапазона 4-байтового знакового целого числа.";
    } else if (code == NullPointer) {
        return "Ошибка: передан нулевой указатель.";
    } else if (code == InvalidBase) {
        return "Ошибка: недопустимая система счисления (поддерживаются только 2, 10, 16).";
    } else if (code == NoError) {
        return ""; // Нет ошибки
    } else {
        return "Неизвестная ошибка.";
    }
}
