#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    printf("Введите номер задания:");
    int task = icheck();
    scanf("%d", &task);

    double x, y;
    int correct = 0;


    switch(task)
    {
        case 1:
            while(!correct) {
                printf("Введите x:");
                x = icheck();
                printf("Введите у:");
                y = icheck();

                if(x < DBL_MAX-DBL_EPSILON && y < DBL_MAX-DBL_EPSILON){
                    correct = 1;
                } else{
                    printf("\nПовторите ввод:");
                }
            }
            teFunc(x, y);
        break;

        default:
            printf("Задание не готово или не существует.");
        break;
    }

    return 0;
}
