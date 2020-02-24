#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include "arrayutils.h"

/*
 * Интеграл методом трапеций
*/

double methodTrap(double, double, int, double(*f)(double));
double formula_1(double);
double formula_2(double);

int main3(){
    printf("Первая формула: %.3lf\n", methodTrap(1, 2, 20, formula_1));
    printf("Вторая формула: %.3lf", methodTrap(-2, 3, 20, formula_2));
    putchar('\n');
    return 0;
}


double methodTrap(double a, double b, int n, double(*f)(double)){
//h - отрезок интегрирования
//xi - промежуточное значение аргумента
double h = (b - a) / n, sum = 0, xi;
    for (int i = 1; i < n; i++){
        xi = a + i*h;
        sum += f(xi);
    }
    return h*((f(a)+f(b)) / 2 + sum);
}

double formula_1(double x){
    return 1/(x*x + 1);
}

double formula_2(double x){
    return cos(5*x);
}
