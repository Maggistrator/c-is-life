#include <stdlib.h>
#include <stdio.h>

#ifndef boolean
#define boolean char
#endif
#define true 1
#define false 0

/**
* Check It 0.0.5.0
* Функция вводит число, и проверяет его валидность
* Поддерживается только консольный ввод
* @param data - слово, вводимое до первого пробела, табуляции, или переноса строки
*/
//TODO: (вне контекста лаб) заменить цикл на возвращение некорректного значения
//TODO: заменить выводимое значение указателем на него, тогда маячком неверного ответа станет NULL
double checkit(char* data, size_t size){
    double value;               /*будущий результат работы функции*/
    boolean isValid;

    do{
        isValid = true;
        scanf("%s", data);

        /*Цикл, обходящий массив символов, и проверяющий их на валидность*/
        for(char i = 0, c = data[0]; c != '\0'; i++, c = data[i]){
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
                    /*Если символ недпустим, флаг валидности переклюается, и функция
                    потребует ввести число заново*/
                    isValid = false;
                    break;
            }
        }
        sscanf(data, "%lf", &value);
        if(!isValid) printf("nope, try again\n");
    } while(!isValid);
    return value;
}

