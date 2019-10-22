#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

double mathTask(double x){
    double result;
    printf("\n---Задание 2---\n");
    if(checkAVA()) result = x*x - cos(log(sqrt(fabs(x)))/tan(exp(-x)));
    else printf("Выражение не удовлетворяет области определения\n");
    return result;
}

/*Allowed Values Area*/
int checkAVA(double x){
    return fabs(x) < DBL_EPSILON;
}


