#include <stdio.h>
#include <stdlib.h>

/**Процедура печатающая все непростые числа от 2 до k*/
void printk(int k){
    int gcd(int, int);
    for(int i = 2; i <= k; i++){
        for(int j = 1; j < i; j++){
            if(gcd(i, j) != 1) {
                printf("%d ", i);
                break;
            }
        }
    }
    printf("\n");
}
