#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEF_STR_LEN 256
/*
* Дан файл, содержащий некоторый текст. Удалить из этого
* файла все фразы, содержащие слово «мама».
*
* Низкий уровень: Исходный файл к первой задаче не содержит русских
* букв, каждая фраза расположена на отдельной строке, словами
* считаются группы символов между группами пробелов.
*/
int main() {
    FILE *fp;
    char name[] = "res/dontread.me";
    if ((fp = fopen(name, "r")) == NULL){
        printf("Не удалось открыть файл");
        return 1;
    }

    char c;
    int j = 0;
    int newlines = 0;
    char** textfile = (char**)malloc(sizeof(char*) * (newlines+1));
    *textfile = (char*)malloc(sizeof(char)*DEF_STR_LEN);
    puts("Содержимое файла:");
    while((c = fgetc(fp)) != EOF) {
        if(c != '\n'){
            if(j < DEF_STR_LEN) {
                *(*(textfile+newlines)+j) = c;
                putc(c, stdout);
                j++;
            }
        } else {
            *(*(textfile+newlines)+j) = '\n';
            putc('\n', stdout);
            j=0;
            newlines++;
            textfile = (char**)realloc(textfile, sizeof(char*) * (newlines+1));
            *(textfile+newlines) = (char*)malloc(sizeof(char) * DEF_STR_LEN);
        }
    }

    fp=freopen(NULL,"w",fp);
    putc('\n', stdout);
    char *word, *temp = (char*)malloc(sizeof(char)*DEF_STR_LEN);
    puts("Результирующий файл:");
    for(int i = 0; i < newlines; i++){
        strcpy(temp, *(textfile+i));
        int allowed = 1;
        char* source = temp;
        while((word = strtok(source, " .,!?\n")) != NULL && allowed){
            if(strcmp(word, "mama")) {
                source = NULL;
            }else allowed = 0;
        }
        if(allowed) {
            fputs(*(textfile+i), fp);
            printf("%s", *(textfile+i));
        }
    }

    free(temp);
    fclose(fp);
    for(int i = 0; i < newlines; i++) free(*(textfile+i));
    free(textfile);
    return 0;
}






