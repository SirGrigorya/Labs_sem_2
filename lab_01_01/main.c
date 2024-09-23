#include <stdio.h>
#include <math.h>

#define EPS 0.000001

int readCoordinates(float *x, float *y);
float fun(float x);
int whereIsPoint(float x, float y);

int readCoordinates(float *x, float *y) {
    int result = 1;
    char extra;
    if (scanf("%f %f", x, y) != 2) {
        result = 0;
    }
    if (scanf("%c", &extra) == 1 && extra != '\n') {
        result = 0;
    }
    return result;
}

float fun(float x) {
    float y;
    y = 0.5*x + 1;
    return y;
}

int whereIsPoint(float x, float y) {
    float f = fun(x);
    int result;
    if (EPS > fabs(f - y)) {
        result = 1;
    }
    else if (EPS < f - y) {
        result = 2;
    }
    else if (EPS > f - y) {
        result = 3;
    }
    else {
        result = 0;
    }
    return result;
}

int main()
{
    float x, y;
    int res;
    if(!readCoordinates(&x, &y)) {
        return 1;
    }
    else {
        res = whereIsPoint(x, y);
        if(res == 1) {
            printf("Point is on the line");
        }
        else if(res == 2) {
            printf("Point is below the line");
        }
        else {
            printf("Point is above the line");
        }
        return 0;
    }
}
