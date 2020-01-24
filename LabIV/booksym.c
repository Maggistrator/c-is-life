#include <stdio.h>
#include <stdlib.h>
#define PAGES 450
#define LINES_PER_PAGE 80
#define SYMBOLS_PER_LINE 64


/*
 *  Книга – трехмерный массив букв (три координаты – страница,
 *  строка, номер буквы в строке). Вывести на экран n -ю строку со стра-
 *  ницы p книги, содержащей 450 страниц, на каждой странице которой
 *  размещается по 80 строк, длина каждой строки 64 символа.
 */
int main(){
    char ***book = (char***)malloc(sizeof(char**) * PAGES);

    for(int i = 0; i < PAGES; i++){
        printf("Страница %d. \
        \nЗаполните её построчно.\
        \nВам доступно %d строк, и %d символов на строку.\n",
        i, LINES_PER_PAGE, SYMBOLS_PER_LINE);

        char **page = *(book+i);
        *page = (char**)malloc(sizeof(char*) * LINES_PER_PAGE);
        for(int j = 0; j < LINES_PER_PAGE; j++){
            printf("%d:",j);
            char *line = *(page+j);
            fgets(line, SYMBOLS_PER_LINE, stdin);
            printf("you've got: \"%s\" here", line);
        }
    }

    for(int i = 0; i < PAGES; i++){
        char **page = *(book+i);
        for(int j = 0; j < LINES_PER_PAGE; j++){
            char *line = *(page+j);
            free(line);
        }
        free(page);
    }
    free(book);
    return 0;
}

