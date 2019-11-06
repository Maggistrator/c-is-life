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
double expNegX(double);             /*Задача 7*/
double InfRow(double);              /*Задача 8*/
void printk(int);                   /*Задача 9*/
double controlFunc(double);         /*Контрольная функция для проверки бесконечного ряда из задания 8*/

int main()
{
    double x, y, result;
    int task = 1;
    while(task){
    printf("Введите номер задания, или 0 для того, чтобы закрыть программу:");
    task = (int)checkit();

    switch((int)task)
    {
        case 0: printf("Программа успешно завершила работу.");
                break;
        case 1:
            printf("Эта программа вычисляет математическую функцию при помощи тернарного оператора.\n");
            printf("Введите x:"); x = checkit();
            printf("Введите y:"); y = checkit();
            result = teFunc(x, y);
            printf("x = %.2lf y = %.2lf\n результат вычислений: %.2lf\n", x, y, result);
        break;
        case 2:
            printf("Эта программа вычисляет математическое выражение при помощи стандартной библиотеки математики.\n");
            printf("Введите x:"); x = checkit();
            result = mathTask(x);
            printf("Результат вычислений: %.2lf\n", result);
        break;
        case 3:
            printf("Эта программа определяет четверть, в которой лежит точка с заданными координатами.\n");
            printf("Введите координату x:"); x = checkit();
            printf("Введите координату y:"); y = checkit();
            result = restrictPt(x, y);
            /*В связи с ленью разработчика, вывод остался в вызываемой функции*/
        break;
        case 4:
            printf("Эта программа вычисляет ряд всех четных или нечетных до заданного числа.\n");
            while(printf("Введите N (> 2):"), 1)
                if((x = checkit()) < 3) printf("Ошибка. Попробуйте ещё раз.\n");
                else break;
            EORow((int)x);
            break;
        case 5:
            printf("Эта программа вычисляет первое число Фибоначчи больше заданного N.\n");
            while(printf("Введите N (>1):"), 1)
                if((x = checkit()) < 2) printf("Ошибка. Попробуйте ещё раз.\n");
                else break;
            result = FibonacciGTN((int)x);
            printf("Искомое число: %.lf\n", result);
        break;
        case 6:
            printf("Эта программа упрощает обыкновенную дробь.\n");
            printf("Введите числитель:"); x = checkit();
            printf("Введите знаменатель:"); y = checkit();
            GCDReFract((int)x, (int)y);
        break;
        case 7:
            printf("Эта программа вычисляет сумму членов бесконечного ряда с точностью до 1e-4.\n");
            printf("Введите x:"); x = checkit();
            result = expNegX(x);
            printf("Результат работы функции: %lf\n", result);
            printf("Проверочная функция: %lf\n", exp(-x));
        break;
        case 8:
            printf("Эта программа вычисляет сумму ряда и сравнивает с контрольной функцией.\n");
            while(printf("Введите x (0,1 >= x <= 0,8):"), 1)
                if((x = checkit()) < 0.1 || x > 0.8)
                    printf("Ошибка. Попробуйте ещё раз.\n");
                else break;
            result = InfRow(x);
            printf("Сумма ряда: %.4lf\n",result);
            result = controlFunc(x);
            printf("Контрольная функция: %.4lf\n",result);
        break;
        case 9:
            printf("Эта программа печатает все числа от 2 до k, исключая простые.\n");
            while(printf("Введите k (>= 2):"), 1)
                if((x = checkit()) < 2) printf("Ошибка. Попробуйте ещё раз.\n");
                else break;
            printk((int)x);
            break;
        default:
            printf("Задание не готово или не существует.\n");
        break;
    }
    }
    return 0;
}
