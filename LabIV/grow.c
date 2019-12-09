#include "lab_iv.h"
/*
  g_row: Growing Row
  Определить, является ли массив из 20-элементов возрастающей последовательностью
  (Следует ли мне вынести ввод за пределы функции?)
*/
boolean grow(void)
{
    double arr[20];
    for(int i = 0; i < 20; i++){
        arr[i] = i;
    }
    boolean isGrowing = true;
    int i = 0;
    while(isGrowing && i < 19){
    printf("%.1lf  ", arr[i]);
        if(arr[i] >= arr[i+1]) {
            isGrowing = false;
            printf("\ndat vector shrinks! just like youer pinas :3");
        }
        i++;
    }
    if(isGrowing) printf("\nduh, dat vector grows so fucking big!");
    return isGrowing;
}
