#include <stdio.h>
#include <stdlib.h>

/**Greater Common Divisor Reducing Fraction - функция, сокращающая дробь используя наибольший общий делитель*/
void GCDReFract(int x, int y){
    int gcd(int, int);
    int gc_divisor = gcd(abs(x), abs(y));
    int numerator = x/gc_divisor;
    int denominator = y/gc_divisor;
    char sign = (numerator*denominator > 0) ? '+' : '-';
    printf("Сокращение дроби даст: %c%d/%d\n", sign, abs(numerator), abs(denominator));
}

int gcd(int x, int y){
    int gcd;
    for (int i = 1; i <= x && i <= y; i++){
       if (x % i == 0 && y % i == 0)
          gcd = i;
    }
    return gcd;
}
