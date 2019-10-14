#include <stdio.h>
#include <stdlib.h>

/**Функция, вычисленная тернарным оператором*/
/*
    |x + y  |  x>0
    |xy     |  x<=0 y<0
    |5x     |  все остальные случаи
*/
int teFunc(double x, double y){
    printf("\n---Задание 1---\n");
    double result;
    result = (x > 0) ? x+y : (x<=0 && y<0 ? x*y : 5*x);
    printf("x = %.2lf y = %.2lf\n результат вычислений: %.2lf", x, y, result);
    return result;
}
