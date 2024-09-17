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

double fun(double x) {  //ВЫЧИСЛЕНИЕ ФУНКЦИИ
    double y;
    y = 0.5*x + 1;
    return y;
}

int whereIsPoint(double x, double y) { //ПРОВЕРКА РАСПОЛОЖЕНИЯ ТОЧКИ
    double f = fun(x);
    int result = 1;
    if (EPS > fabs(f - y)) {
        result = 1;
    }
    else if (EPS < f - y) {
        result = 2;
    }
    else if (EPS > f - y) {
        result = 3;
    }
    return result;
}

int main(int argc, char *argv[])
{
    double x, y;
    int res;
    printf("\nLine equation: y = 0.5x + 1\nEnter point coordinates:\n");
    if(!read(&x, &y)) {
        printf("\nResult: Incorrect input\n");
    }
    else {
        res = whereIsPoint(x, y);
        if(res == 1) {
            printf("\nResult: Point is on the line\n");
        }
        else if(res == 2) {
            printf("\nResult: Point is below the line\n");
        }
        else {
            printf("\nResult: Point is above the line\n");
        }
    }
    return 0;
}
