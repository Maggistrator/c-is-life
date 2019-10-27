#include <stdio.h>
#include <stdlib.h>

/**Greater Common Divisor Reducing Fraction - функция, сокращающая дробь
используя наибольший общий делитель*/
void GCDReFract(int x, int y){
    int gcd;
    for (int i = 1; i <= x && i <= y; i++){
       if (x % i == 0 && y % i == 0)
          gcd = i;
    }
    printf("Наибольший общий делитель %d и %d это: %d", x, y, gcd);
    printf("Сокращение дроби даст: %d/%d\n", x/gcd, y/gcd);
}
