#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double recalc2EpsRecurrent(double, double, long, int);

/**Exponent of Negative X, высчитывает экспоненту от -x при помощи разложения на ряд Маклорена*/
double expNegX(double x){
    return 1 + recalc2EpsRecurrent(x, 1, 1, 1);
}

int depth = 2000;
int current_depth = 0;
double recalc2EpsRecurrent(double x, double numerator, long denominator, int i){
    current_depth++;
    int sign = i % 2 ? -1 : 1;
    numerator *= x;
    denominator *= i++;
    printf("n=(%d) * %.4lf / %d\n", sign, numerator, denominator);
    double func = sign * numerator / denominator;
    printf("n = %.4lf\n",func);

    if(current_depth > depth) {
        printf("too deep");
        return func;
    } else if(abs(func) < 1e-4) return func;
    else return func += recalc2EpsRecurrent(x, numerator, denominator, i);
}
