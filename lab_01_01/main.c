#include <cstdio>
#include <math.h>

#define EPS 0.000001

int read(float *x, float *y);
float fun(float x);
int whereIsPoint(float x, float y);

int read(float *x, float *y) {
    int err = 1;
    err = scanf("%lf%lf", x, y);
    if(err != 2) {
        err = 0;
    }
    return err;
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
    if(!read(&x, &y)) {
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
