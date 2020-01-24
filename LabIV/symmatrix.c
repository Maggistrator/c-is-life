#include <stdio.h>
#include <stdlib.h>
#include "arrayutils.h"
#include <float.h>

#define LEN 4

int main4(){
    double **matrix = (double**)malloc(sizeof(double*) * LEN);

    printf("Введите массив из %d чисел, через пробел: ", LEN);
    for(int i = 0; i < LEN; i++) {
        for(int j = 0; j < LEN; j++) {
            printf("Введите %d-й элемент матрицы:9",i+j);
            char* source = fgets(source, 32, stdin);
            *(*(matrix+i)+j)= atoi(source);
        }
    }
    printmx(matrix, LEN, LEN);

    for(int i = 0;  i < LEN; i++){
        for(int j = 0; j < LEN; j++){
            double element = *(*(matrix + i)+j);
            double symmetric_element = *(*(matrix + LEN-j)+LEN-i);
            if(element - symmetric_element > DBL_EPSILON) {
                printf("Матрица НЕ симметрична относительно побочной диагонали.");
                break;
            }
        }
        if(!(LEN-i)) printf("Матрица симметрична относительно побочной диагонали!");
    }

    for(int i = 0; i < LEN; i++) free(*(matrix + i));
    free(matrix);
}
