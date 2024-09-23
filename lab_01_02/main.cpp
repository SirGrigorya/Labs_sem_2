#include <cstdio>
#include <math.h>

#define EPS 0.000001

int read(float *x, float *y);
float fun1(float x);
float fun2(float x);
float fun3(float x);
int isPointOnTheLine(float x, float y);
int isPointAmidstTheLines(float x, float y);

int read(float *x, float *y) {
    int err = 1;
    err = scanf("%lf%lf", x, y);
    if(err != 2) {
        err = 0;
    }
    return err;
}

float fun1(float x) {
    float y = 2 * x + 2;
    return y;
}

float fun2(float x) {
    float y = 0.5 * x - 1;
    return y;
}

float fun3(float x) {
    float y = -x + 2;
    return y;
}

int isPointOnTheLine(float x, float y) {
    float f1 = fun1(x), f2 = fun2(x), f3 = fun3(x);
    int result = 0;
    if (EPS > fabs(f2 - y) and EPS > fabs(f1 - y)) {
        result = 1;
    }
    else if (EPS > fabs(f2 - y) and EPS > fabs(f3 - y)) {
        result = 2;
    }
    else if (EPS > fabs(f1 - y) and EPS > fabs(f3 - y)) {
        result = 3;
    }
    else if (EPS > fabs(f1 - y)) {
        result = 4;
    }
    else if (EPS > fabs(f2 - y)) {
        result = 5;
    }
    else if (EPS > fabs(f3 - y)) {
        result = 6;
    }
    return result;
}

int isPointAmidstTheLines(float x, float y) {
    float f1 = fun1(x), f2 = fun2(x), f3 = fun3(x);
    int result = 0;
    if((EPS < f1 - y) and (EPS > f2 - y) and (EPS > f1 - y)) {
        result = 7;
    }
    else if((EPS < f1 - y) and (EPS < f2 - y) and (EPS > f3 - y)) {
        result = 8;
    }
    else if((EPS < f1 - y) and (EPS < f2 - y) and (EPS < f3 - y)) {
        result = 9;
    }
    else if((EPS > f1 - y) and (EPS < f2 - y) and (EPS < f3 - y)) {
        result = 10;
    }
    else if((EPS > f1 - y) and (EPS > f2 - y) and (EPS < f3 - y)) {
        result = 11;
    }
    else if((EPS > f1 - y) and (EPS > f2 - y) and (EPS > f3 - y)) {
        result = 12;
    }
    else if((EPS < f1 - y) and (EPS > f2 - y) and (EPS < f3 - y)) {
        result = 13;
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
        res = isPointOnTheLine(x, y);
        if (res > 0) {
            if(res == 1) {
                printf("Point placed on line 1 and 2");
            }
            else if(res == 2) {
                printf("Point placed on line 2 and 3");
            }
            else if(res == 3) {
                printf("Point placed on line 1 and 3");
            }
            else if(res == 4) {
                printf("Point placed on line 1");
            }
            else if(res == 5) {
                printf("Point placed on line 2");
            }
            else if(res == 6) {
                printf("Point placed on line 3");
            }
        }
        else {
            res = isPointAmidstTheLines(x, y);
            if(res == 7) {
                printf("Point placed in region 1");
            }
            else if(res == 8) {
                printf("Point placed in region 2");
            }
            else if(res == 9) {
                printf("Point placed in region 3");
            }
            else if(res == 10) {
                printf("Point placed in region 4");
            }
            else if(res == 11) {
                printf("Point placed in region 5");
            }
            else if(res == 12) {
                printf("Point placed in region 6");
            }
            else {
                printf("Point placed in region 7");
            }
            return 0;
        }
    }
}
