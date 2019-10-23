#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/*...*/
double mathTask(double x){
    double result;
    if(checkAVA()) result = x*x - cos(log(sqrt(fabs(x)))/tan(exp(-x)));
    else printf("Выражение не удовлетворяет области определения\n");
    return result;
}

/*Allowed Values Area. Вычисление области определения функции*/
int checkAVA(double x){
    return fabs(x) < DBL_EPSILON;
}


