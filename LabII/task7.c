#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Recalc2EpsRecurrent(double, long, int);

/**Infinity Row высчитывает сумму ряда с определенной точностью*/
double ExpNegX(double x){
    return 1 + Recalc2EpsRecurrent(x, 1, 1);
}

int depth = 2000;
int current_depth = 0;
double Recalc2EpsRecurrent(double x, long n, int i){
    current_depth++;
    int sign = i % 2 ? -1 : 1;
    printf("f(x)=%d * %lf / %d\n", sign, x, n);
    double f = sign * x / (n *= ++i);
    if(current_depth > depth) {
        printf("too deep");
        return 0;
    }
    if(abs(f) < 1E-4) return f;
    else return f += Recalc2EpsRecurrent(x*x, n, i);
}

