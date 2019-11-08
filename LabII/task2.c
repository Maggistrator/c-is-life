#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/*...*/
double mathTask(double x){
    double result;
    if(fabs(x) > DBL_EPSILON && cos(exp(-x) > DBL_EPSILON)){
        result = x*x - cos(log(sqrt(fabs(x)))/tan(exp(-x)));
    }
    else printf("Выражение не удовлетворяет области определения\n");
    return result;
}
