#include <stdio.h>
#include <math.h>

#define EPS 0.000001
#define RES_1 1
#define RES_2 2
#define RES_3 3
#define RES_4 4
#define RES_5 5
#define RES_6 6
#define RES_7 7
#define RES_8 8
#define RES_9 9
#define RES_10 10
#define RES_11 11
#define RES_12 12
#define RES_13 13

int readCoordinates(float *x, float *y);
float fun1(float x);
float fun2(float x);
float fun3(float x);
int isPointOnTheLine(float x, float y);
int isPointAmidstTheLines(float x, float y);

int readCoordinates(float *x, float *y) {
    int result = 1;
    if (scanf("%f %f", x, y) != 2) {
        result = 0;
    }
    return result;
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
    float f1 = fun1(x) - y, f2 = fun2(x) - y, f3 = fun3(x) - y;
    int result;
    if (EPS > fabs(f2) && EPS > fabs(f1)) {
        result = 1;
    }
    else if (EPS > fabs(f2) && EPS > fabs(f3)) {
        result = 2;
    }
    else if (EPS > fabs(f1) && EPS > fabs(f3)) {
        result = 3;
    }
    else if (EPS > fabs(f1)) {
        result = 4;
    }
    else if (EPS > fabs(f2)) {
        result = 5;
    }
    else if (EPS > fabs(f3)) {
        result = 6;
    }
    else {
        result = 0;
    }
    return result;
}

int isPointAmidstTheLines(float x, float y) {
    float f1 = fun1(x), f2 = fun2(x), f3 = fun3(x);
    int result = 0;
    if((EPS < f1) && (EPS > f2) && (EPS > f3)) {
        result = 7;
    }
    else if((EPS < f1) && (EPS < f2) && (EPS > f3)) {
        result = 8;
    }
    else if((EPS < f1) && (EPS < f2) && (EPS < f3)) {
        result = 9;
    }
    else if((EPS > f1) && (EPS < f2) && (EPS < f3)) {
        result = 10;
    }
    else if((EPS > f1) && (EPS > f2) && (EPS < f3)) {
        result = 11;
    }
    else if((EPS > f1) && (EPS > f2) && (EPS > f3)) {
        result = 12;
    }
    else if((EPS < f1) && (EPS > f2) && (EPS < f3)) {
        result = 13;
    }
    return result;
}

void onLineOutput(int res){
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

void amidstLinesOutput(int res) {
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
}

int main()
{
    float x, y;
    int res;
    if(!readCoordinates(&x, &y)) {
        return 1;
    }
    else {
        res = isPointOnTheLine(x, y);
        if (res > 0) {
            if(res == 1) {
                onLineOutput(res);
            }
        }
        else {
            res = isPointAmidstTheLines(x, y);
            if(res == 7) {
                amidstLinesOutput(res);
            }
        return 0;
        }
    }
}
