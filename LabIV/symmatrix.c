#include <stdio.h>
#include <stdlib.h>
#include "arrayutils.h"
#include <float.h>
#include <errno.h>

#define LEN 4

int main4(){
    char* source;
    double **matrix = (double**) malloc(sizeof(double*) * LEN);
    for(int i = 0; i < LEN; i++) *(matrix + i) = (double*)malloc(sizeof(double) * LEN);

    for(int i = 0; i < LEN; i++) {
        for(int j = 0; j < LEN; j++) {
            printf("Введите %d-й элемент матрицы:",i+j+1);
            scanf("%s", source);
            *(*(matrix+i)+j)= dcheckit(source);
            if(errno != 0) {
                perror("whoa");
                errno = 0;
                j--;
            }
        }
    }
    printmx(matrix, LEN, LEN);

    boolean isSymmetric = yup;
    for(int i = 0;  i < LEN; i++){
        for(int j = 0; j < LEN; j++){
            double element = *(*(matrix + i)+j);
            double symmetric_element = *(*(matrix + LEN-j-1)+LEN-i-1);
            if(element - symmetric_element > DBL_EPSILON) {
                isSymmetric = nope;
                break;
            }
        }
    }
    if(isSymmetric) printf("Матрица симметрична относительно побочной диагонали.\n");
    else printf("Матрица НЕ симметрична относительно побочной диагонали.\n");

    for(int i = 0; i < LEN; i++) free(*(matrix + i));
    free(matrix);
    return 0;
}
