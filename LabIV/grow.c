#include "arrayutils.h"
#include <stdlib.h>
#include <stdio.h>

#define ARR_LEN 5
/**
* Определить, является ли массив из 20-элементов возрастающей последовательностью
*/

int grow(double*, int);

int main1(){
    double *arr = (double*)calloc(ARR_LEN, sizeof(double));
    printf("Введите %d чисел через пробел: ", ARR_LEN);
    darelins(arr, ARR_LEN);
    printf("\n%s\n", grow(arr, ARR_LEN)
    ? "Это возрастающая последовательность."
    : "Это НЕ возрастающая последовательность.");
}

/*grow: Growing Row*/
int grow(double *arr, int len){
    int i = 0, isGrowing = yup;
    while(isGrowing && i < len-1){
        if(*(arr + i) >= *(arr+i+1)) {
            isGrowing = nope;
        }
        i++;
    }
    return isGrowing;
}
