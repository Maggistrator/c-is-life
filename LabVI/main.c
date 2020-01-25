#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 64

/**
* Дана строка символов. Удалить из нее все кратные
* рядом стоящие одинаковые символы, оставив по одному
* (АААВВСС >> АВС).
*/
int main()
{
    int clrm(char*, char*);
    printf("Введите строку:\n");
    char *str = (char*)malloc(sizeof(char)*STRLEN);
    str = fgets(str, STRLEN, stdin);
    int deleted = clrm(str, str);
    printf("Строка, очищенная от дубликатов:%s\n", str);
    printf("Удалено повторяющихся символов:%d", deleted);
    free(str);
    return 0;
}

/**
* Clone Remover
* @return Возвращает кол-во удалённых элементов.
*/
int clrm(char *src, char *out){
    int j = 0;
    int deleted = 0;
    for(char curel = (char)*src, i = 0; curel != '.' && curel != '\0'; ++i, curel = *(src+i)){
        if(curel == *(src+i+1)) deleted++;
        else {
            *(out + j) = curel;
            j++;
        }
    }
    *(out+j) = '\0';
    return deleted;
}




















