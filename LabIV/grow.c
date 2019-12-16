#include "arrayutils.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define ARR_LEN 5

int grow(double*, int);

int main(){
    double *arr = calloc(ARR_LEN, sizeof(double));
    printf("Введите %d чисел через пробел: ", ARR_LEN);
    darelins(arr, ARR_LEN);
    //for(int i = 0; i < 5; i++) printf("%lf ", arr[i]);
    //putchar('\n');
    printf("\n%s", grow(arr, ARR_LEN)
    ? "Это возрастающая последовательность."
    : "Это НЕ возрастающая последовательность.");
}

/*
  g_row: Growing Row
  Определить, является ли массив из 20-элементов возрастающей последовательностью
*/
int grow(double *arr, int len){
    int i = 0, isGrowing = yup;
    while(isGrowing && i < len-1){
        //printf("%lf ", *(arr+i));
        if(*(arr + i) >= *(arr+i+1)) {
            isGrowing = nope;
            //printf("\nsquee!\n");
        }
        i++;
    }
    //printf("\ngrows:%d\n",isGrowing);
    return isGrowing;
}
