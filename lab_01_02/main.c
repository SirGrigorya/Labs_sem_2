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

int onLine(float f) {
    float fl = 0;
    if (EPS > fabs(f)) {
        fl = 1;
    }
    return fl;
}

int underLine(float f) {
    float fl = 0;
    if (EPS > f) {
        fl = 1;
    }
    return fl;
}

int aboveLine(float f) {
    float fl = 0;
    if (EPS < f) {
        fl = 1;
    }
    return fl;
}

int isPointOnTheLine(float x, float y) {
    float f1 = fun1(x) - y, f2 = fun2(x) - y, f3 = fun3(x) - y;
    int result;
    if (onLine(f2) && onLine(f1)) {
        result = RES_1;
    }
    else if (onLine(f2) && onLine(f3)) {
        result = RES_2;
    }
    else if (onLine(f1) && onLine(f2)) {
        result = RES_3;
    }
    else if (onLine(f1)) {
        result = RES_4;
    }
    else if (onLine(f2)) {
        result = RES_5;
    }
    else if (onLine(f3)) {
        result = RES_6;
    }
    else {
        result = 0;
    }
    return result;
}

int isPointAmidstTheLines(float x, float y) {
    float f1 = fun1(x) - y, f2 = fun2(x) - y, f3 = fun3(x) - y;
    int result = 0;
    if(underLine(f1) && aboveLine(f2) && aboveLine(f3)) {
        result = RES_7;
    }
    else if(underLine(f1) && underLine(f2) && aboveLine(f3)) {
        result = RES_8;
    }
    else if(underLine(f1) && underLine(f2) && underLine(f3)) {
        result = RES_9;
    }
    else if(aboveLine(f1) && underLine(f2) && underLine(f3)) {
        result = RES_10;
    }
    else if(aboveLine(f1) && aboveLine(f2) && underLine(f3)) {
        result = RES_11;
    }
    else if(aboveLine(f1) && aboveLine(f2) && aboveLine(f3)) {
        result = RES_12;
    }
    else if(underLine(f1) && aboveLine(f2) && underLine(f3)) {
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
