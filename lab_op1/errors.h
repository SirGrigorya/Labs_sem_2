#ifndef ERRORS_H
#define ERRORS_H

typedef enum {
    NoError = 0,
    InvalidInput,
    OutOfRange,
    NullPointer,
    InvalidBase,
} ErrorCode;

const char* getErrorMessage(ErrorCode code);

#endif // ERRORS_H
