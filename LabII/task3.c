#include <stdio.h>
#include <stdlib.h>
#include <float.h>

/*Restrict Point algorythm*/
int restrictPt(double x, double y){
    char area = 0, ax = 'n', ay = 'n';

    if(x < -DBL_EPSILON && y > DBL_EPSILON) area = 1;
    else if(x > DBL_EPSILON && y > DBL_EPSILON) area = 2;
    else if(x < -DBL_EPSILON && y < -DBL_EPSILON) area = 3;
    else if(x > DBL_EPSILON && y < -DBL_EPSILON) area = 4;
    else {
        ax = (y > -DBL_EPSILON && y < DBL_EPSILON) ? 'y' : 'n';
        ay = (x > -DBL_EPSILON && x < DBL_EPSILON) ? 'y' : 'n';
    }
    //из соображений компактности вывода он не выведен из функции
    printf("Четверть: %d, принадлежит ax:%c, принадлежит ay:%c", area, ax, ay);
    return area;
}
