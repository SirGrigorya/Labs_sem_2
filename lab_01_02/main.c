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

int onLine1(float x, float y) {
    float f1 = fun1(x) - y;
    float fl = 0;
    if (EPS > fabs(f1)) {
        fl = 1;
    }
    return fl;
}

int onLine2(float x, float y) {
    float f2 = fun1(x) - y;
    float fl = 0;
    if (EPS > fabs(f2)) {
        fl = 1;
    }
    return fl;
}

int onLine3(float x, float y) {
    float f3 = fun1(x) - y;
    float fl = 0;
    if (EPS > fabs(f3)) {
        fl = 1;
    }
    return fl;
}

int underLine1(float x, float y) {
    float f1 = fun1(x) - y;
    float fl = 0;
    if (EPS > fabs(f1)) {
        fl = 1;
    }
    return fl;
}

int underLine2(float x, float y) {
    float f2 = fun1(x) - y;
    float fl = 0;
    if (EPS > fabs(f2)) {
        fl = 1;
    }
    return fl;
}

int underLine3(float x, float y) {
    float f3 = fun1(x) - y;
    float fl = 0;
    if (EPS > fabs(f3)) {
        fl = 1;
    }
    return fl;
}

int aboveLine1(float x, float y) {
    float f1 = fun1(x) - y;
    float fl = 0;
    if (EPS < fabs(f1)) {
        fl = 1;
    }
    return fl;
}

int aboveLine2(float x, float y) {
    float f2 = fun1(x) - y;
    float fl = 0;
    if (EPS < fabs(f2)) {
        fl = 1;
    }
    return fl;
}

int aboveLine3(float x, float y) {
    float f3 = fun1(x) - y;
    float fl = 0;
    if (EPS < fabs(f3)) {
        fl = 1;
    }
    return fl;
}

int isPointOnTheLine(float x, float y) {
    int result;
    if (onLine2(x, y) && onLine1(x, y)) {
        result = RES_1;
    }
    else if (onLine2(x, y) && onLine3(x, y)) {
        result = RES_2;
    }
    else if (onLine1(x, y) && onLine3(x, y)) {
        result = RES_3;
    }
    else if (onLine1(x, y)) {
        result = RES_4;
    }
    else if (onLine2(x, y)) {
        result = RES_5;
    }
    else if (onLine3(x, y)) {
        result = RES_6;
    }
    else {
        result = 0;
    }
    return result;
}

int isPointAmidstTheLines(float x, float y) {
    int result = 0;
    if(underLine1(x, y) && aboveLine2(x, y) && aboveLine3(x, y)) {
        result = RES_7;
    }
    else if(underLine1(x, y) && underLine2(x, y) && aboveLine3(x, y)) {
        result = RES_8;
    }
    else if(underLine1(x, y) && underLine2(x, y) && underLine3(x, y)) {
        result = RES_9;
    }
    else if(aboveLine1(x, y) && underLine2(x, y) && underLine3(x, y)) {
        result = RES_10;
    }
    else if(aboveLine1(x, y) && aboveLine2(x, y) && underLine3(x, y)) {
        result = RES_11;
    }
    else if(aboveLine1(x, y) && aboveLine2(x, y) && aboveLine3(x, y)) {
        result = RES_12;
    }
    else if(underLine1(x, y) && aboveLine2(x, y) && underLine3(x, y)) {
        result = RES_13;
    }
    return result;
}

void onLineOutput(int res){
    if(res == RES_1) {
        printf("Point placed on line 1 and 2");
    }
    else if(res == RES_2) {
        printf("Point placed on line 2 and 3");
    }
    else if(res == RES_3) {
        printf("Point placed on line 1 and 3");
    }
    else if(res == RES_4) {
        printf("Point placed on line 1");
    }
    else if(res == RES_5) {
        printf("Point placed on line 2");
    }
    else if(res == RES_6) {
        printf("Point placed on line 3");
    }
}

void amidstLinesOutput(int res) {
    if(res == RES_7) {
        printf("Point placed in region 1");
    }
    else if(res == RES_8) {
        printf("Point placed in region 2");
    }
    else if(res == RES_9) {
        printf("Point placed in region 3");
    }
    else if(res == RES_10) {
        printf("Point placed in region 4");
    }
    else if(res == RES_11) {
        printf("Point placed in region 5");
    }
    else if(res == RES_12) {
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
                onLineOutput(res);
        }
        else {
            res = isPointAmidstTheLines(x, y);
            amidstLinesOutput(res);
        return 0;
        }
    }
}
