#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main() {
    char *s = (char*) malloc(sizeof(char) * 8);
    int noexit = 1;
    while(noexit){
        printf("Введите номер задания, или 0 чтобы выйти: ");
        s = fgets(s, 8, stdin);
        int choice = atoi(s);
            switch(choice){
            case 1: main1();
                    break;
            case 2: main2();
                    break;
            case 0: noexit = 0;
                    break;
            default:
                puts("Такого задания нет.");
                break;
            }
        }
    free(s);
    return 0;
}
