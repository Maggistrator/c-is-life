#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

int mathTask(double x){
    double result;
    printf("\n---Задание 2---\n");
    if(checkAVA()){
        result = x*x - cos(log(sqrt(fabs(x)))/tan(exp(-x)));
        printf("x = %.2lf результат вычислений: %.2lf", x, result);
    } else {
        printf("kek, error");
    }

    return result;
}

/*Allowed Values Area*/
int checkAVA(double x){
    return fabs(x) < DBL_EPSILON;
}


