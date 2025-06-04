#ifndef EXECUTE_H
#define EXECUTE_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Figure2D.h"

using namespace std;

enum operation_type
{
    OP_LOAD_DATA_FROM_FILE = 0,
    OP_GET_FIGURE = 1
};

enum error_type {
    NO_ERROR = 0,
    FILE_NOT_OPENED,
    FILE_NOT_READED,
    NORMALIZE_NOT_FLOAT,
    NORMALIZE_WRONG,
    UNKNOWN_ERROR
};

struct operation_t
{
    operation_type type;
    string fileName;
    float minRange;
    float maxRange;
    float rotX;
    float rotY;
    float rotZ;
    float scale;
};

struct result_t
{
    error_type error;
    Figure2D figure;
};

result_t *executeOperation(operation_t *operation);


#endif // EXECUTE_H
