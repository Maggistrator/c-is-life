#include <stdio.h>
#include <stdlib.h>

/**Ternar Function. Функция, вычисленная тернарным оператором*/
/*
    |x + y  |  x>0
    |xy     |  x<=0 y<0
    |5x     |  все остальные случаи
*/
double teFunc(double x, double y){
    double result = (x > 0) ? x+y : ((x<=0 && y<0) ? x*y : 5*x);
    return result;
}
