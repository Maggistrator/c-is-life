#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGES 2
#define LINES_PER_PAGE 2
#define SYMBOLS_PER_LINE 64


/*
 *  Книга – трехмерный массив букв (три координаты – страница,
 *  строка, номер буквы в строке). Вывести на экран n -ю строку со стра-
 *  ницы p книги, содержащей 450 страниц, на каждой странице которой
 *  размещается по 80 строк, длина каждой строки 64 символа.
 */
void main5(){
    char ***book = (char***)malloc(sizeof(char**) * PAGES);

    for(int i = 0; i < PAGES; i++){
        printf("Страница %d. \
        \nЗаполните её построчно.\
        \nВам доступно %d строк, и %d символов на строку.\n",
        i+1, LINES_PER_PAGE, SYMBOLS_PER_LINE);

        *(book+i) = (char**)malloc(sizeof(char*) * LINES_PER_PAGE);
        for(int j = 0; j < LINES_PER_PAGE; j++){
            printf("%d:",j+1);
            *(*(book+i)+j) = (char*)malloc(sizeof(char)*SYMBOLS_PER_LINE);
            fgets(*(*(book+i)+j), SYMBOLS_PER_LINE, stdin);
            strtok(*(*(book+i)+j), "\n");
        }
    }

    int x = 0, y = 0, isCorrect = 0;
    printf("Введите номер страницы и номер строки, которую нужно напечатать.\n");
    while(!isCorrect){
        puts("Страница:");
        scanf("%d", &x);
        puts("Строка:");
        scanf("%d", &y);
        if(x > 0 && x <= PAGES){
            if(y > 0 && y <= LINES_PER_PAGE){
                isCorrect = 1;
            } else puts("Нет такой строки, попробуйте ещё раз.");
        } else puts("Нет такой страницы, попробуйте ещё раз.");
    }

    char **page = *(book+x-1);
    char *line = *(page+y-1);
    printf("Это строка: %s\n", line);

    for(int i = 0; i < PAGES; i++){
        char **page = *(book+i);
        for(int j = 0; j < LINES_PER_PAGE; j++){
            char *line = *(page+j);
            free(line);
        }
        free(page);
    }
    free(book);
}

