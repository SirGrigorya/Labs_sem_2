#include <cstdio>
#include <math.h>

#define EPS 0.000001    //ПОГРЕШНОСТЬ

int read(double *x, double *y) {    //ЧТЕНИЕ И ФИЛЬТРАЦИЯ ВВОДНЫХ
    char err = 1;
    err = scanf("%lf%lf", x, y);
    if(err != 2) {
        err = 0;
    }
    return err;
}

double fun1(double x) {     //ВЫЧИСЛЕНИЕ ФУНКЦИИ 1
    double y = 2 * x + 2;
    return y;
}

double fun2(double x) {     //ВЫЧИСЛЕНИЕ ФУНКЦИИ 2
    double y = 0.5 * x - 1;
    return y;
}

double fun3(double x) {     //ВЫЧИСЛЕНИЕ ФУНКЦИИ 3
    double y = -x + 2;
    return y;
}

int isPointOnTheLine(double x, double y) {   //ПРОВЕРКА РАСПОЛОЖЕНИЯ ТОЧКИ НА ЛИНИЯХ
    double f1 = fun1(x), f2 = fun2(x), f3 = fun3(x);
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

int isPointAmidstTheLines(double x, double y) {   //ПРОВЕРКА РАСПОЛОЖЕНИЯ ТОЧКИ В ОБЛАСТЯХ
    double f1 = fun1(x), f2 = fun2(x), f3 = fun3(x);
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

int main(int argc, char *argv[])
{
    double x, y;
    int res;
    printf("\nLine equations:\ny = 2x + 2\ny = -x + 2\ny = 0.5x - 1\nEnter point coordinates:\n");
    if(!read(&x, &y)) {
        printf("\nResult: Incorrect input\n");
    }
    else {
        res = isPointOnTheLine(x, y);
        if (res > 0) {
            if(res == 1) {
                printf("\nPoint placed on line 1 and 2\n");
            }
            else if(res == 2) {
                printf("\nPoint placed on line 2 and 3\n");
            }
            else if(res == 3) {
                printf("\nPoint placed on line 1 and 3\n");
            }
            else if(res == 4) {
                printf("\nPoint placed on line 1\n");
            }
            else if(res == 5) {
                printf("\nPoint placed on line 2\n");
            }
            else if(res == 6) {
                printf("\nPoint placed on line 3\n");
            }
        }
        else {
            res = isPointAmidstTheLines(x, y);
            if(res == 7) {
                printf("\nPoint placed in region 1\n");
            }
            else if(res == 8) {
                printf("\nPoint placed in region 2\n");
            }
            else if(res == 9) {
                printf("\nPoint placed in region 3\n");
            }
            else if(res == 10) {
                printf("\nPoint placed in region 4\n");
            }
            else if(res == 11) {
                printf("\nPoint placed in region 5\n");
            }
            else if(res == 12) {
                printf("\nPoint placed in region 6\n");
            }
            else {
                printf("\nPoint placed in region 7\n");
            }
        }
    }
}
