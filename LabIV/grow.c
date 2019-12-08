#include "lab_iv.h"
/*
  g_row: Growing Row
  Определить, является ли массив из 20-элементов возрастающей последовательностью
  (Следует ли мне вынести ввод за пределы функции?)
*/
boolean grow(void)
{
    double arr[];

    boolean isGrowing = true;
    int i = 1;
    while(isGrowing && i < 20){
    printf("%.1lf  ",*(arr+i));
        if(*(arr+i-1) >= *(arr+i)) {
            isGrowing = false;
            printf("dat vector shrinks! just like youer pinas :3");
        }
        i++;
    }
    if(isGrowing) printf("duh, dat vector grows so fucking big!");
    free(arr);
    return isGrowing;
}
