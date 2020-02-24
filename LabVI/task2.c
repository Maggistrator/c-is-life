#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 64
/*
 * Дана строка символов до точки.
 * Подсчитать, сколько слов она содержит.
*/

void main2(){
    char str[LEN];
    printf("Введите строку:");
    fgets(str, sizeof(str), stdin);
    int words = 0;
    if(strlen(str)>1){
        strcpy(str, strtok(str, ".\0\n"));
        char *istr;
        istr = strtok (str, " ");
        while (istr != NULL && !isspace(*istr)){
            istr = strtok (NULL, " ");
            words++;
        }
    }
    printf("Строка содержит %d слов\n", words);
}
