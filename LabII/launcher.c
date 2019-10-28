#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <locale.h>
#include <math.h>

double checkit(void);               /*Функция проверки ввода*/
double teFunc(double, double);      /*Задача 1*/
double mathTask(double);            /*Задача 2*/
int restrictPt(double, double);     /*Задача 3*/
void EORow(int);                    /*Задача 4*/
int FibonacciGTN(int);              /*Задача 5*/
void GCDReFract(int, int);          /*Задача 6*/
double ExpNegX(double);             /*Задача 7*/

int main()
{
    char * out;
    if ((out = setlocale(LC_ALL, "ru_RU.UTF-8")) == NULL)
        printf("Russian unaviable.\n");
        else printf("Locale is:%s\n",out);
    double x, y, task=1, result;
    while(task){
    printf("Введите номер задания, или 0 для того, чтобы закрыть программу:");
    task = checkit();

    switch((int)task)
    {
        case 1:
            printf("Эта программа поощряет нечитаемый код.\n");
            printf("Введите x:"); x = checkit();
            printf("Введите y:"); y = checkit();
            result = teFunc(x, y);
            printf("x = %.2lf y = %.2lf\n результат вычислений: %.2lf", x, y, result);
        break;
        case 2:
            printf("Эта программа вычисляет математическое выражение (Вариант 1).\n");
            printf("\nВведите x:"); x = checkit();
            result = mathTask(x);
            printf("x = %.2lf результат вычислений: %.2lf", x, result);
        break;
        case 3:
            printf("Эта программа определяет четверть, в которой лежит точка с заданными координатами.\n");
            printf("Введите x:"); x = checkit();
            printf("Введите y:"); y = checkit();
            result = restrictPt(x, y);
            /*В связи с ленью разработчика, вывод остался в вызываемой функции*/
        break;
        case 4:
            printf("Эта программа вычисляет ряд всех четных или нечетных до заданного числа.\n");
            printf("Введите N (> 2):");
            EORow((int)checkit());
            break;
        case 5:
            printf("Эта программа вычисляет первое число Фибоначчи больше заданного.\n");
            while(printf("Введите N (>= 1):"), 1)
                if((result = checkit()) < 2) printf("nope, try again\n");
                else break;
            result = FibonacciGTN((int)result);
            printf("Искомое число: %.lf\n", result);
        break;
        case 6:
            printf("Эта программа упрощает простую дробь.\n");
            printf("Введите x:\n");
            x = checkit();
            printf("Введите y:\n");
            y = checkit();
            GCDReFract((int)x, (int)y);
        break;
        case 7:
            printf("Введите x:");
            x = checkit();
            result = ExpNegX(x);
            printf("Результат работы функции: %lf",result);
            printf("Проверочная функция: %lf", exp(-x));
        break;
        default:
            printf("Задание не готово или не существует.\n");
        break;
    }
    }
    return 0;
}
