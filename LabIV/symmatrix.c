#include <stdio.h>
#include <stdlib.h>
#include "arrayutils.h"

#define LEN 4

int main4(){
    double **matrix = (double**)malloc(sizeof(char*) * LEN);
    for(int i = 0; i < LEN; i++) dfillarran(*(matrix + i), LEN);
    printmx(matrix, LEN, LEN);

    for(int i = 0; i < LEN; i++){
        for(int j = LEN; j > 0; j--){

        }
    }

    for(int i = 0; i < LEN; i++) free(*(matrix + i));
    free(matrix);
}
