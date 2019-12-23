#include "arrayutils.h"
#include <stdlib.h>
#include <stdio.h>
#include <float.h>

#define ROWS 5
#define COLUMNS 7

int minposeofmatrix(double**, int, int);

int main3() {
    /*Инициализируем статический массив*/
    double twodimarray[ROWS][COLUMNS];

    /*Инициализируем динамическую матрицу*/
    double **matrix = (double**) malloc(sizeof(double*) * ROWS);
    for(int i = 0; i < ROWS; i++) *(matrix + i) = (double*)malloc(sizeof(double) * COLUMNS);

    for(int i = 0; i < ROWS; i++){
        dfillarran(*(matrix + i), COLUMNS);
        dfillarran(twodimarray[i], COLUMNS);
    }

    puts("Динамическая матрица:");
    printmx(matrix, ROWS,COLUMNS);

    puts("Статический массив:");
    printmx(twodimarray, ROWS, COLUMNS);

    /*freeing mem*/
    for(int i = 0; i < ROWS; i++) free(*(matrix + i));
    free(matrix);
}



/**Minimal Positive Element of Matrix*/
int minposeofmatrix(double **matrix, int rows, int col){
    double min = DBL_MAX;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < col; j++){
            if(*(*(matrix + i) + j) > 0 && *(*(matrix + i) + j) < min) {
                min = *(*(matrix + i) + j);
            }
        }
    }
    return min;
}


