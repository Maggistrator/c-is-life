#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double recFunc(double, double, int);
double controlFunc(double);

/**Infinity Row высчитывает сумму ряда с определенной точностью*/
double InfRow(double x){
    return recFunc(x, x, 1);
}

double recFunc(double x, double deltanum, int i){
    double func;
    deltanum *= x;
    int denominator = i++;
    func = deltanum / denominator;
    if(fabs(func) < 1e-6) return func;
    else return func += recFunc(x, deltanum*cos(i*M_PI/3), i);
}

/*Вычисление контрольной функции*/
double controlFunc(double x){
    double func = -1./2*log(1-2*x*cos(M_PI/3.) + x*x);
    return func;
}
