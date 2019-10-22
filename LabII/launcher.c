#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <locale.h>

double checkit(void);
int teFunc(double, double);
int mathTask(double);

int main()
{
    setlocale(LC_ALL, "Rus");
    double x, y;
    double task = checkit();
    printf("task is:%lf", task);

    switch((int)task)
    {
        case 1:
            printf("\nВведите x:");
            x = checkit();
            printf("\nВведите y:");
            y = checkit();
            teFunc(x, y);
        break;
        case 2:

        break;

        default:
            printf("Задание не готово или не существует.");
        break;
    }
    return 0;
}
