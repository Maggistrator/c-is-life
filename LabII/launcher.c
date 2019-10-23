#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <locale.h>

double checkit(void);               /*Функция проверки ввода*/
double teFunc(double, double);      /*Задача 1*/
double mathTask(double);            /*Задача 2*/
int restrictPt(double, double);     /*Задача 3*/
void EORow(int);                    /*Задача 4*/
int FibonacciIsGay(int);

int main()
{
    setlocale(LC_ALL, "Rus");
    double x, y, task, result;
    printf("Введите номер задания:");
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
            printf("Введите N (>= 1):");
            result = FibonacciIsGay((int)checkit());
            printf("Искомое число: %.lf", result);
        break;
        default:
            printf("Задание не готово или не существует.");
        break;
    }
    return 0;
}
