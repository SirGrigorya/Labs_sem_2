#include <stdio.h>
#include <math.h>

int readCoordinates(float *x, float *y, float *z) {
    int result = 1;
    if (scanf("%f%f%f", x, y, z) != 3) {
        result = 0;
    }
    return result;
}

int findStep(float x, float y, float z) {
    float step;
    step = (fabs(x) + fabs(y)) / (z - 1);
        return step;
}

int mathFunction(float x) {
    float res = tan(x) + sqrt(x);
    return res;
}

int main() {
    float x, y, z;
    if (!readCoordinates(&x, &y, &z)) {
        return 1;
    }
    else {
        return 0;
    }
}
