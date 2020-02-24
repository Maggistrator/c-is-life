#include <stdio.h>
#include <stdlib.h>
#include "arrayutils.h"
#define SIZE_A 6
#define SIZE_B 8

/*
 * Определить, состоят ли целочисленные массивы А (16)
 * и В(18) из одинаковых наборов значений.
 * Элементы в массивах могут располагаться в произвольном порядке.
 * Одно и тоже значение может встречаться неоднократно.
 *
 * Алгоритм:
 * Помощи функции поиска дубликатов из arrayutils.c
 * проверяем все элементы, пока не встретится элемент, у которого
 * нет дубликатов. Если такой элемент не встретится - наборы элементов
 * у массивов совпадают.
 *
 * ПРИМЕЧАНИЕ: тип double используется исключительно
 * из соображений совместимости с существующей кодовой базой
*/

void main2(){
    /*Выделим память*/
    double *A = (double*)calloc(SIZE_A, sizeof(double));
    double *B = (double*)calloc(SIZE_B, sizeof(double));

    /*Заполним массивы значениями с клавиатуры*/
    printf("Введите %d значений через пробел: ", SIZE_A);
    darelins(A, SIZE_A);
    printf("\nВведите %d значений через пробел: ", SIZE_B);
    darelins(B, SIZE_B);

    /*Ищем дубликаты в массивах*/
    boolean isaelco = yup;//isAllElementsCommon
    for(int i = 0; i < SIZE_B; i++){
        if(!iselrep(&A, *(B+i), 1, SIZE_A, nope)){
            isaelco = nope;
            break;
        }
    }
    /*Выводим результат*/
    putchar('\n');
    if(isaelco) printf("Массивы содержат одинаковые элементы\n");
    else printf("Массивы состоят из разных элементов\n");
}

