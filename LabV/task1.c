#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "arrayutils.h"
#define ARR_LEN 5
#define MX_ROWS 3
#define MX_COLS 3


/*
* Поменять местами максимальные элементы массива А (45) и
* матрицы В (6х9). Если в массиве максимальное значение имеют не-
* сколько элементов, массив считается некорректным.
*/

void main1()
{
    double *hurray = (double*)calloc(ARR_LEN, sizeof(double));
    double **matrix = (double**)malloc(sizeof(double*) * MX_ROWS);
    printf("Введите двумерную матрицу чисел %dx%d (через пробел):\n", MX_ROWS, MX_COLS);
    for(int i = 0; i < MX_ROWS; i++){
        *(matrix+i) = (double*)malloc(sizeof(double) * MX_COLS);
        darelins(*(matrix+i), MX_COLS);
        putchar('\n');
    }
    printf("Введите массив из %d элементов(через пробел):", ARR_LEN);
    darelins(hurray, ARR_LEN);

    double mxmax, arrmax;
    int mxi, mxj, aj;

    mxmax = findmxmax(matrix, MX_ROWS, MX_COLS, &mxmax, &mxi, &mxj);
    printf("\nМаксимальный элемент матрицы:%2.lf с индексами %dx%d\n", mxmax, mxi+1, mxj+1);
    arrmax = findmxmax(&hurray, 1, ARR_LEN, &arrmax, NULL, &aj);
    printf("Максимальный элемент массива:%2.lf с индексом %d\n", arrmax, aj+1);
    if(!iselrep(&hurray, arrmax, 1, ARR_LEN, nope)) {
        printf("В массиве несколько элементов имеют максимальное значение! Продолжение работы невозможно!\n");
        return 1;
    }

    /*обменяем максимальные элементы матрицы и массива*/
    double temp = *(*(matrix+mxi)+mxj);
    *(*(matrix+mxi)+mxj) = *(hurray+aj);
    *(hurray+aj) = temp;

    puts("Обменяем местами максимальные элементы матрицы и массива..");
    puts("Получившийся массив:");
    printa(hurray, ARR_LEN);
    puts("Итоговые значения матрицы:");
    printmx(matrix, MX_ROWS, MX_COLS);
}

