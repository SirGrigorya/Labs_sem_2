#include <stdio.h>
#include <math.h>

#define EPS 0.000001
#define RES_1 1
#define RES_2 2
#define RES_3 3

int readCoordinates(float *x, float *y);
float fun(float x);
int whereIsPoint(float x, float y);

int readCoordinates(float *x, float *y) {
    int result = 1;
    if (scanf("%f %f", x, y) != 2) {
        result = 0;
    }
    return result;
}

float fun(float x) {
    float y;
    y = 0.5*x + 1;
    return y;
}

int onLine(float f) {
    return EPS > fabs(f);
}

int underLine(float f) {
    return EPS < f;
}

int aboveLine(float f) {
    return EPS > f;
}

int whereIsPoint(float x, float y) {
    float f = fun(x) - y;
    int result;
    if (onLine(f)) {
        result = RES_1;
    }
    else if (underLine(f)) {
        result = RES_2;
    }
    else if (aboveLine(f)) {
        result = RES_3;
    }
    else {
        result = 0;
    }
    return result;
}

void finalOutput(int res) {
    if(res == RES_1) {
        printf("Point is on the line");
    }
    else if(res == RES_2) {
        printf("Point is below the line");
    }
    else {
        printf("Point is above the line");
    }
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
        finalOutput(res);
        return 0;
    }
}
