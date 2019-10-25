#include <stdio.h>
#include <stdlib.h>

int StolenCode(double x, double y, gcd){
    printf("Enter two integer values: \n");
    scanf("%d %d", &x, &y);
    for (int i = 1; i <= x && i <= y; i++){
       if (x % i == 0 && y % i == 0)
          gcd = i;
    }
    printf("GCD of %d and %d is: %d", x, y, gcd);
    return next;
}
