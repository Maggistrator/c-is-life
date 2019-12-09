#include "arrayutils.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
/*
  g_row: Growing Row
  Определить, является ли массив из 20-элементов возрастающей последовательностью
*/
boolean grow(void){
    double arr[20];
    char *row_data = calloc(32, sizeof(char));
    for(int i = 0; i < 20; i++){
        printf("insert value:");
        scanf("%s", row_data);
        arr[i] = (int)dcheckit(row_data);
        if(errno != 0) {
            perror("(!)");
            i--;
        }
    }
    free(row_data);
    boolean isGrowing = yup;
    int i = 0;
    while(isGrowing && i < 19){
    printf("%.1lf  ", arr[i]);
        if(arr[i] >= arr[i+1]) {
            isGrowing = nope;
            printf("\ndat vector shrinks! just like youer pinas :3");
        }
        i++;
    }
    if(isGrowing) printf("\nduh, dat vector grows so fucking big!");
    return isGrowing;
}
