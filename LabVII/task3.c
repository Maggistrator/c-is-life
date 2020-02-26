#include <stdio.h>
#include <stdlib.h>
/*
* Компоненты бинарного файла – вещественные числа.
* Изменить знак у каждого третьего числа на противоположный.
*/

void reinit_file();
void main3(){
    //reinit_file(); use 4 debug
    int elements = 0;
    double num;
    int number_of_elements_per_time = 1;
    double * arr = (double*)calloc(1, sizeof(double));

    FILE* f;
    f = fopen("res/data.bin", "rb");

    puts("Содержимое файла до перезаписи:");
    while(fread(&num, sizeof(double), number_of_elements_per_time, f) == number_of_elements_per_time)
    {
        elements++;
        arr = (double*)realloc(arr, sizeof(double)*elements);
        if(((elements) % 3 == 0)) *(arr+elements-1) = -num;
        else*(arr+elements-1) = num;
        printf("%d: %.2lf\n", elements, num);
    }
    putchar('\n');

    f = freopen(NULL, "wb", f);
    for (int i = 0; i < elements; i++)
        fwrite((void*)&arr[i], sizeof(double), 1, f);

    puts("Содержимое файла после перезаписи:");
    for(int i = 0; i < elements; i++) printf("%d: %.2lf\n", i+1, *(arr + i));

    fclose(f);
    free(arr);
}

void reinit_file(){
    double arr[7] = { 1.03, 2.07, 4.015, 2.38, 5.78, 9.34, 8.41 };

    FILE* f;
    f = fopen("res/data.bin", "wb");
    for (int i = 0; i < 7; ++i)
        fwrite((void*)&arr[i], sizeof(double), 1, f);
    fclose(f);
    puts("succsess");
}
