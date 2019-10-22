#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <locale.h>

double checkit(void);
double teFunc(double, double);
double mathTask(double);

int main()
{
    setlocale(LC_ALL, "Rus");
    double x, y, task, result;
    printf("Введите номер задания:");
    task = checkit();

    switch((int)task)
    {
        case 1:
            printf("Введите x:"); x = checkit();
            printf("Введите y:"); y = checkit();
            result = teFunc(x, y);
            printf("x = %.2lf y = %.2lf\n результат вычислений: %.2lf", x, y, result);
        break;
        case 2:
            printf("\nВведите x:"); x = checkit();
            result = mathTask(x);
            printf("x = %.2lf результат вычислений: %.2lf", x, result);
        break;
        default:
            printf("Задание не готово или не существует.");
        break;
    }
    return 0;
}
