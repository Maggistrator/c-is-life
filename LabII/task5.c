#include <stdio.h>
#include <stdlib.h>

/*Fibonacci Greater Then N: вычисляет число Фибоначчи больше заданного N*/
int FibonacciGTN(int N){

    int prev = 2, next = 3, temp = next;
    while(N >= next){
        temp = next;
        next += prev;
        prev = temp;
    }
    return next;
}

