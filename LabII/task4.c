#include <stdio.h>
#include <stdlib.h>
#include <float.h>

/*
* Even Odd Row algorythm
* Задача оформлена процедурой, ибо тут возвращать результат не удобно
*/
void EORow(int N){
    if(N > 2){
        if(N % 2) for(int i = 1; i <= N; i+=2) printf("%d  ", i);
        else for(int i = 2; i <= N; i+=2) printf("%d  ", i);
    }
    else printf("Значение не удовлетворяет условию задачи.");
    printf("\n");
}
