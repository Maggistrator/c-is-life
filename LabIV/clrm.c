#include "arrayutils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARR_LEN 5
void findelcl(char**, char*, int);
void clrm(char**, char**, int);


/**
* Сформировать новый массив из элементов исходного линейного
* массива встречающихся в нем только один раз
*/

int main(){
    char **arr = (char**)malloc(sizeof(char*) * ARR_LEN);
    for(int i = 0; i < ARR_LEN; i++){
        printf("Введите произвольные данные: ", );
        scanf();
        putchar()
    }
}

/**
* Обработчик массива строк. Так как элементами входного массива
* будут указатели, они гарантируют уникальность всех
* элементов-ссылок, что позволит как угодно изменять
* расположенные по ним значения.
* Повторяющиеся значения будут заменены указателем на NULL
* а затем удалены при помощи realloc()
* (к примеру, все элементы из конца будут переписаны в
* пустые места в начале, а старые их места затерты на NULL,
* и затем realloc отберёт у них память, но на это нужно много
* времени)
*/
void clrm(char **src, char **out, int len){
    char *current_element;
    for(int i = 0, j = 0; i < len; i++){
        current_element = *(src+i);
        if(current_element != NULL){
            findelcl(src, current_element, len);
            *(out+j++) = current_element;
        }
    }
}

/**Find 'n Delete Clones of obj in arr of len elements*/
void findelcl(char **arr, char *obj, int len){
    boolean first_meeting = yup;
    for(int i = 0; i < len; i++){
        if(!strcmp(*(arr+i), obj)){
            if(first_meeting) {
                first_meeting = nope;
                continue;
            } else{
                *(arr+i) = NULL;
            }
        }
    }
}
