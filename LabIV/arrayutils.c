#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <float.h>

#ifndef boolean
#define boolean char
#define yup 1
#define nope 0
#endif // boolean

typedef enum {TYPE_INT, TYPE_CHAR, TYPE_FLOAT, TYPE_DOUBLE, TYPE_STRING} TYPE;


/**
* Char Check It 0.8.0.0
* Функция проверяет однобайтовое число от -128 до 127 на валидность.
* Цифры от 0 до 9 и числа от -128 до 127 приводятся из символьного вида в циферный, например:
* '2' = 2 (а не её код 50)
* '5''0' = 50
* А односимвольные строки возвращаются в том же виде, например:
* '#' = '#'
* 'a' = 'a'
* если же исходная строка содержит более одного символа, и это не десятичное число, такое значение считается недопустимым, и
* функция вернёт 0
* @param data - исходная строка
*/
char ccheckit(char* str){
    errno = 0;                              /*на старте код ошибки всегда 0*/
    int len = strlen(str);                  /*длина строки*/

    /*Для односимвольной строки любой символ допустим*/
    if(len == 1) {
        if(*str >= '0' && *str <= '9') return atoi(str);
        else return *str;
    } else {
        /*Если символов несколько, они все должны быть цифрами*/
        for(int i = 0, c = str[0]; c != '\0' && i < 4; i++, c = str[i]){
            /*Если символ является числом, переходим к следующему*/
            if(c >= '0' && c <= '9') continue;
            else {
                /*Если символ недпустим, глобальная переменная ошибок errorno примет соответствующий код*/
                errno = 8;
                return 0;
            }
        }
    }

    long int temp = atoi(str);
    if(temp > -129 && temp < 128) return (char)temp;
    else {
        errno = 8;
        return 0;
    }
}


/**
* Double Check It 0.8.0.0
* Функция проверяет вещественное число двойной точности на валидность
* @param data - входная строка, подлежащая парсингу
*/

double dcheckit(char* data){
    /*на старте код ошибки всегда 0*/
    errno = 0;
    /*Цикл, обходящий массив символов, и проверяющий их на валидность*/
    for(int i = 0, c = data[0]; c != '\0'; i++, c = data[i]){
        /*Если символ является числом, переходим к следующему*/
        if(c >= '0' && c <= '9') continue;
        /*Если символ числом не является, проверяем, является ли он допустимым*/
        else switch(c){
            case '-':
            case '.':
            case ',':
            case 'e':
            case 'E':
                /*Если символ допустИм, переходим к следующему*/
                continue;
            default:
                /*Если символ недпустим, флаг валидности переключается, и функция
                потребует ввести число заново*/
                errno = 8;
                return 0;
            }
        }

    /*Парсинг, при помощи волшебной функции, которая и без меня всё умеет*/
    long double value = atof(data);
    /*Проверка на выход за границы диапазона*/
    if(value > DBL_MAX) {
        errno = 8;
        return 0;
    } else return value;
}



/*Array Element Insertion*/
void arelins(void *ptr, TYPE t, int len){

}

