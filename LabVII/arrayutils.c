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
#define boolean unsigned char
#define yup 1
#define nope 0
#endif // boolean

#define IN 10
#define OUT 11

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

/**
* Double Fill Array Randomly
* Заполняет одномерный массив случайными числами
* ps. для матрицы можно в цикле вызвать данный метод для каждой строки
*/
void dfillarran(double *arr, int len) {
    for(int i = 0; i < len; i++){
        *(arr+i) = genrandom(1);
    }
}

/**
* Print Array
* Распечатывает в консоль одномерный массив
* прим. не смотря на простоту, данная функциональность необходима черзвычайно часто
*/
void printa(double* arr, int len){
    for(int i = 0; i < len; i++) printf("%.2lf ", *(arr + i));
    putchar('\n');
}

/**
* Print Matrix
* Распечатывает в консоль двумерную матрицу
* Можно печатать и одномерные массивы, если указать кол-во строк равным 1
* @param rows кол-во строк
* @param col кол-во столбцов
*/
void printmx(double** mx, int rows, int col){
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++){
            printf("%2.lf ", *(*(mx + i)+j));
        }
        putchar('\n');
    }
    putchar('\n');
}

/**
* Find Matrix Max
* Находит максимальный элемент матрицы и возвращает его значение
* Для того, чтобы использовать эту функцию для одномерных массивов, следует передать
* в качестве параметра mx адрес переменной массива(например: &array), а кол-во строк указать 1
* @param mx указатель на матрицу
* @param rows кол-во строк
* @param cols кол-во столбцов
* @param result указатель на переменную результата. Может быть NULL.
* @param sx адрес, куда следует записать индекс строки, где найден элемент. Может быть NULL, если эти данные не важны.
* @param sy адрес, куда следует записать индекс столбца, где найден элемент. Может быть NULL, если эти данные не важны.
* @return максимальный элемент матрицы как вещественное число
*/
double findmxmax(double **mx, int rows, int cols, double* result, int* sx, int* sy){
    double max = DBL_MIN;
    int x, y;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++){
            double* curel = *(mx+i)+j;
            if(max < *curel) {
                max = *curel;
                x = i; y = j;
            }
        }
    }
    if(result != NULL) *result = max;
    if(sx != NULL) *sx = x;
    if(sy != NULL) *sy = y;
    return max;
}

/**
* Is Element Repeat Itself
* Возвращает число копий элемента el
* Можно использовать для одномерных массивов, передав вместо
* указателя на матрицу адрес переменной массива(например: &arr), а в кол-ве строк 1
* @param mx матрица
* @param el исследуемый элемент
* @param rows кол-во строк матрицы
* @param cols кол-во столбцов матрицы
* @param pridx следует ли печатать индексы дубликатов 1-да, 0-нет
* @return кол-во дубликатов элемента. 0 - если элемент не дублируется.
*/
int iselrep(double **mx, double el, int rows, int cols, boolean pridx){
    int repeats = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            double* curel = *(mx + i)+j;
            if(abs(*curel - el) < DBL_EPSILON) repeats++;
            if(pridx) printf("элемент: %2.lf x:%d y:%d\n", *curel, i+1, j+1);
        }
    }
    return repeats;
}


unsigned countWords(char *str){
    int state = OUT;
    unsigned wc = 0;

    while (*str){
        if (*str == ' ' || *str == '\n' || *str == '\t')
            state = OUT;
        else if (state == OUT){
            state = IN;
            ++wc;
        }
        ++str;
    }

    return wc;
}







