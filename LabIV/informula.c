#include "arrayutils.h"
#include <stdlib.h>
#include <stdio.h>
#include <float.h>

#define ROWS 5
#define COLUMNS 7

int main3() {
    /*Инициализируем статический массив*/
    double twodimarray[ROWS][COLUMNS];

    /*Инициализируем динамическую матрицу*/
    double **matrix = (double**) malloc(sizeof(double*) * ROWS);
    for(int i = 0; i < ROWS; i++) *(matrix + i) = (double*)malloc(sizeof(double) * COLUMNS);

    int mx_i, mx_j, mx_fpi, mx_fpj;
    int arr_i, arr_j, arr_fpi, arr_fpj;
    double arr_min = DBL_MAX, mx_min = DBL_MAX;
    double arr_fp = -1, mx_fp = -1;
    boolean mx_first = yup, arr_first = yup;

    for(int i = 0; i < ROWS; i++){
        dfillarran(*(matrix + i), COLUMNS);
        dfillarran(twodimarray[i], COLUMNS);
    }

    puts("Динамическая матрица:");
    for(int i = 0, ce; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; ++j, ce = (int)*(*(matrix + i) + j)){
            printf("%2d ", ce);
            if(ce > 0){
                if(mx_first) {
                    mx_first = nope;
                    mx_fp = ce;
                    mx_fpi = i+1; mx_fpj = j+1;
                }
                if(ce < mx_min) {
                    mx_min = ce;
                    mx_i = i+1; mx_j = j+1;
                }
            }
        }
        putchar('\n');
    }
    putchar('\n');

    puts("Статический массив:");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++){
            printf("%2.lf ", twodimarray[i][j]);
            if((int)twodimarray[i][j] > 0){
                if(arr_first) {
                    arr_first = nope;
                    arr_fp = twodimarray[i][j];
                    arr_fpi = i+1; arr_fpj = j+1;
                }
                if(twodimarray[i][j] < arr_min){
                    arr_min = twodimarray[i][j];
                    arr_i = i+1; arr_j = j+1;
                }
            }
        }
        putchar('\n');
    }
    putchar('\n');

    printf("Минимальный положительный элемент матрицы: %.lf с индексами %dx%d\n", mx_min, mx_i, mx_j);
    printf("Минимальный положительный элемент статического массива: %.lf с индексами %dx%d\n", arr_min, arr_i, arr_j);
    printf("Первый положительный элемент матрицы: %.lf с индексами %dx%d\n", mx_fp, mx_fpi, mx_fpj);
    printf("Первый положительный элемент статического массива: %.lf с индексами %dx%d\n\n", arr_fp, arr_fpi, arr_fpj);

    double mx_S = (mx_i + mx_j) / (double)(mx_fpi + mx_fpj);
    double arr_S = (arr_i + arr_j) / (double)(arr_fpi + arr_fpj);

    printf("Результат вычисления формулы для матрицы: S = (%d + %d) / (%d + %d) = %.2lf\n", mx_i, mx_j, mx_fpi, mx_fpj, mx_S);
    printf("Результат вычисления формулы для статическго массива: S = (%d + %d) / (%d + %d) = %.2lf\n", arr_i, arr_j, arr_fpi, arr_fpj, arr_S);

    /*freeing mem*/
    for(int i = 0; i < ROWS; i++) free(*(matrix + i));
    free(matrix);
}
