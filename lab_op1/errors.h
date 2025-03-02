#ifndef ERRORS_H
#define ERRORS_H

typedef enum {
    NoError,
    InvalidInput,
    OutOfRange
} ErrorCode;

const char *getErrorMessage(ErrorCode code);

#endif // ERRORS_H
