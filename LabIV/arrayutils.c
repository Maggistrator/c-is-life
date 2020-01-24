#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <float.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#ifndef boolean
#define boolean char
#define yup 1
#define nope 0
#endif // boolean

typedef enum {TYPE_INT, TYPE_CHAR, TYPE_FLOAT, TYPE_DOUBLE, TYPE_STRING} TYPE;


/**
* Char Check It 0.8.0.0
* Функция проверяет однобайтовое число на валидность в человечески-итуитивном
* представлении. Так, цифры от 0 до 9 и числа от -128 до 127 приводятся из символьного вида в циферный, например:
* '2' = 2 (а не её код 50)
* '5''0' = 50
* Тогда как одиночные символы становятся собой, например:
* '#' = '#'
* 'a' = 'a'
* Если нужно вводить символы цифер, то валидным вводом будут их коды.
* Если же исходная строка содержит более одного символа, и это не десятичное число, такое значение считается недопустимым, и функция вернёт 0
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
                errno = EINVAL;
                return 0;
            }
        }
    if(strlen(data) == 0) {
        errno = EINVAL;
        return 0;
    }

    /*Парсинг, при помощи волшебной функции, которая и без меня всё умеет*/
    long double value = atof(data);
    /*Проверка на выход за границы диапазона*/
    if(value > DBL_MAX) {
        errno = EOVERFLOW;
        return 0;
    } else return value;
}

/**
* void Console Insert(char* source_string)
* Платформозависимая, консольная функция ввода символов в строку src.
* Вводит (подряд, в "raw" режиме!) любые символы, останавливаясь на SPACE и ENTER
*/
void cinsert(char* src){
    system ("/bin/stty raw isig");
    int c, i = 0;
    while(((c = getchar()) != ' ') && (c != '\n')) {
        *(src + i++) = c;
    }
    *(src + i) = '\0';
    system ("/bin/stty -raw");
    return ;
}

/**Char Array Element Insertion
* Функция позволяет заполнить заданное кол-во
* элементов массива char с проверкой введенных значений
*/
void carelins(char *ptr, int len){
    char *raw_data = (char*)calloc(32, sizeof(char));
    for(int i = 0; i < len; i++){
        cinsert(raw_data);
        *(ptr + i) = ccheckit(raw_data);
        if(errno != 0) {
            perror("try again");
            i--;
        }
    }
    free(raw_data);
    return;
}

/**
* Double Array Element Insertion
* Функция позволяет заполнить заданное кол-во
* элементов массива вещественных чисел с проверкой введенных значений
*/
void darelins(double *ptr, int len){
    char *raw_data = (char*)calloc(32, sizeof(char));
    for(int i = 0; i < len; i++){
        cinsert(raw_data);
        *(ptr + i) = dcheckit(raw_data);
        if(errno != 0) {
            perror("try again");
            i--;
        }
    }
    free(raw_data);
    return;
}

static int bias = 1;

/**
* Generate Random
* digits - максимальное кол-во разрядов в результирующем случайном числе
*/
double genrandom(int digits) {
    time_t result = time(NULL);
    return ((result | (++bias * result) * ((bias ^ result) % 3 == 0 ? bias * -1 : bias)) % (int)pow(10, digits)) + (bias % 10 * 0.1);
}

/**Double Fill Array Randomly*/
void dfillarran(double *arr, int len) {
    for(int i = 0; i < len; i++){
        *(arr+i) = genrandom(1);
    }
}

/**Print Array*/
void printa(double* arr, int len){
    for(int i = 0; i < len; i++) printf("%.lf ", *(arr + i));
    putchar('\n');
}

/**Print Matrix*/
void printmx(double** mx, int rows, int col){
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++){
            printf("%2.lf ", *(*(mx + i)+j));
        }
        putchar('\n');
    }
    putchar('\n');
}
