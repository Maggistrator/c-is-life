/**Функция продвинутой проверки ввода.
Конечно, можно было бы обойтись и примитивной, но имеет смысл раз и навсегда сделать хорошо*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <float.h>

#define INVALID -1      /*Нужные константы*/
#define NEGATIVE -1
#define INTEGER 10
#define REAL 0.1
#define POSITIVE 1
#define multiplier char

#define ERR_INVALID_CHARACTER 1     /*Коды ошибок*/
#define ERR_INVALID_MINUS 2
#define ERR_INVALID_COMMA 3
#define ERR_INVALID_EXPONENT 4
#define ERR_INVALID_VALUE_EXPONENT 5


char allowed[14] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', ',', '.', 'e'}; /*Массив допустимых символов*/

double icheck(){
    int valueof(char);
    //char number[16];                                          /*Введённое число*/
    char s, minus = 0, error = 0, zap = 0, exponent = 0;    /*s - считываемый символ*/
    double value = 0, drob = 1;                             /*value - значение числа; drob - порядок дробной части*/
    multiplier sign = POSITIVE, sign_exponent = POSITIVE;   /*Знаки значения и экспоненты*/
    int num_do_zap = 0, num_pos_zap = 0, step = 0, j = 0, it;   /*num_do_zap кол-во цифр до зяпятой; num_pos_zap - после; step - степень(значение экспоненты); j -просто счётчик*/
    while (((s = getchar()) != '\n')&&(error == 0))         /*Цикл будет считывать символы до нажатия enter, обрабатывать до первой ошибки*/
    //scanf("%[^\n]",number);
    //for(it = 0; it < (sizeof(number) / sizeof(char)); it++)
    {
        //s = number[it];
        int index = valueof(s);                             /*index - присваивается значение функции valueof*/
        if (index == INVALID)                               /*Если символы нет в массиве допустимых символов, то error будет присвоен код ошибки Недопустимый символ*/
            error = ERR_INVALID_CHARACTER;
        else                                                /*Иначе просматривается какой это символ и выбирается способ работы сним*/
            switch (allowed[index])
        {
        case '-':
            if (((num_do_zap == 0)||(exponent == 1))&&(minus == 0)) /*Если был введён минус в серидине числа или экспоненты, то error присвоится код ошибки недопустимый минус*/
            {
                if (num_do_zap == 0)            /*Если минус был введён верно, то меняется значение знака либо числа, либо экспоненты*/
                    sign = NEGATIVE;
                else
                    sign_exponent = NEGATIVE;
                minus = 1;
            }
            else error = ERR_INVALID_MINUS;
            break;
        case ',':
        case '.':
            if ((zap == 0)&&(exponent == 0)&&(num_do_zap != 0)) /*Если запятая была введена до цифр, либо в экспоненте, либо это вторая запятая, то error присваивается значение кода ошибки недопустимая запятая*/
                zap = 1;
            else
                error = ERR_INVALID_COMMA;
            break;
        case 'e':
            if ((exponent != 0)||((zap == 0)&&(num_do_zap == 0))||((zap != 0)&&(num_pos_zap == 0))) /*Если знак экспоненты идёт перед числами, либо сразу после запятой, либо это не первый знак экспоненты, то  error присваивается значение кода ошибки Неверная экспонента*/
                error = ERR_INVALID_EXPONENT;
            else
            {
                exponent = 1; /*Если условия if'a не выполняются, то minus зануляется*/
                minus = 0;
            }
            break;
        default:        /*Сюда попадают цифры*/
            if (exponent == 1)          /*Если был знак экспоненты, то "собирается"(умножается на 10 текущее значение степени и прибавляется новая введённая цифра)*/
            {
                step *= INTEGER;
                step += s - '0';
                if (abs(step) > 307)    /*Выход за диапазон double(да, в double максимальная степень - abs(308), но это значение 1,7...e308, и если я сделаю 308, то будет считаться, что 3e308 тоже входит в double, а это не так)*/
                    error = ERR_INVALID_VALUE_EXPONENT;
            }
            else
                if (zap == 0)       /*Если запятой не было, то число "собирается" и увеличивается счётчик цифр до запятой*/
                {
                    value *= INTEGER;
                    value += s - '0';
                    num_do_zap ++;
                }
                else                /*Если запятая была, то число "собирается иначе"(порядок дробной части делится на 10, умножается на введённую цифру и прибавляется к числу*/
                {
                    drob *= REAL;
                    value += drob * (s - '0');
                    num_pos_zap ++;
                }
        }
    }
    if (sign_exponent < 0)      /*Число возводится в степень(экспоненту)*/
        for(j; j < step; j++)
            value *= REAL;
    else
        for(j; j < step; j++)
            value *= INTEGER;
    value *= sign;              /*Числу приписывается знак(минус, если есть)*/
    switch (error)              /*Вывод в соответствии с ошибкой*/
    {
    case 0:                     /*0 - нет ошибок*/
        printf("%g\n", value);
        break;
    case 1:
        printf("Был введён недопустимый символ\n");
        break;
    case 2:
        printf("Был введён недопустимый минус\n");
        break;
    case 3:
        printf("Была введена недопустимая запятая(точка)\n");
        break;
    case 4:
        printf("Было введено больше одной экспоненты\n");
        break;
    case 5:
        printf("Выход за диапазон типа double\n");
        break;
    }

    /*Если работа завершена корректно, возвращаем значение. В противном случае - недопустимый MAX_DOUBLE*/
    value = (error == 0) ? value : DBL_MAX;
    return value;
}

                                /*Функция определяет допустимый ли был введён символ*/
int valueof(char c){             /*В функцию поступает символ*/
    int a = INVALID;
    int i;

    /*Если символ допустимый, то возвращается его индекс в массиве; если нет, то возвращается -1*/
    for(i = 0; i<14; ++i)
        if (c == allowed[i])
        {
            a = i;
            break;
        }
    return a;
}
