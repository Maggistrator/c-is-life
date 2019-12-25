#include "arrayutils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARR_LEN 5
void findelcl(char**, char*, int);
int clrm(char**, char**, int);


/**
* Сформировать новый массив из элементов исходного линейного
* массива встречающихся в нем только один раз
*/

int main2(){
    char **arr = (char**)malloc(sizeof(char*) * ARR_LEN);
    printf("Введите сходный массив из %d значений: \n", ARR_LEN);
    for(int i = 0; i < ARR_LEN; i++){
        *(arr + i) = malloc(sizeof(char)*5);
        cinsert(*(arr + i));
    }

    puts("\nМассив, очищенный от дубликатов:");
    int deleted = clrm(arr, arr, ARR_LEN);
    if (deleted > 0) realloc(arr, sizeof(char*) * (ARR_LEN - deleted));
    for(int i = 0; i < ARR_LEN - deleted; i++) printf("%s ", *(arr + i));
    putchar('\n');

    /*Freeing mem*/
    for(int i = 0; i < ARR_LEN - deleted; i++) free(*(arr + i));
    free(arr);
}

/**
* Clone Remover - заменяет все дубликаты элементов в src на NULL, и записывает чистый результат в out
* Если передать в качестве src и out один и тот же массив, его элементы автоматически сдвинутся на
* кол-во удалённых элементов.
* @return Возвращает кол-во удалённых элементов.
*/
int clrm(char **src, char **out, int len){
    char *current_element;
    int deleted = 0;
    for(int i = 0, j = 0; i < len; i++){
        current_element = *(src + i);
        if(current_element != NULL){
            findelcl(src + i, current_element, len - i);
            *(src + i) = (char *) NULL;
            *(out + j) = current_element;
            j++;
        } else deleted++;
    }
    return deleted;
}

/**Find 'n Delete Clones of obj in arr of len elements*/
void findelcl(char **arr, char *obj, int len){
    boolean first_meeting = yup;
    for(int i = 0; i < len; i++){
        if(*(arr + i) != NULL){
            if(!strcmp(*(arr+i), obj)){
                if(first_meeting) {
                    first_meeting = nope;
                    continue;
                } else {
                    *(arr + i) = (char*)NULL;
                }
            }
        } else continue;
    }
}
