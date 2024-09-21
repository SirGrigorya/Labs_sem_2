#include <cstdio>
#include <math.h>

#define EPS 0.000001    //ПОГРЕШНОСТЬ

int read(double *x, double *y);
double fun(double x);
int whereIsPoint(double x, double y);

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

int main()
{
    double x, y;
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
    }
    return 0;
}
