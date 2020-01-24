#include "arrayutils.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main() {
    char *s = (char*) malloc(sizeof(char) * 8);
    int noexit = 1;
    while(noexit){
        puts("Введите номер задания, или 0 чтобы выйти: ");
        gets(s);
        int choice = (int)dcheckit(s);
        if(errno == 0) {
            switch(choice){
                case 1: main1();
                        break;
                case 2: main2();
                        break;
                case 3: main3();
                        break;
                case 4: main4();
                        break;
                case 5: main5();
                        break;
                case 0: noexit = 0;
                        break;
                default:
                    puts("Такого задания нет.");
                    break;
            }
        } else {
            perror("Попробуйте ещё раз. Ошибка");
            errno = 0;
            continue;
        }
    }
    free(s);
    return 0;
}
