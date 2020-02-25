#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayutils.h"

#define MAX_WORD_LEN 24
#define MAX_LINE_LEN 256

/*
 * В текстовом файле хранится целочисленная матрица.
 * Заменить в ней все числа, кратные 7, наибольшим значением
 * матрицы. Полученный файл вывести на экран.
*/

void replace7(double**, int, int);
int parsemx(char**, double**, int);
unsigned countWords(char*) ;
void parseMatrix(FILE * , double** , int , int );
int main2() {
    FILE *fp;
    char name[] = "res/matrix";
    if ((fp = fopen(name, "r")) == NULL){
        printf("Не удалось открыть файл");
        return 1;
    }

    char c; //current char
    int rid = 0; //row_id
    int newlines = 0, words = 0;
    char** textfile = (char**)malloc(sizeof(char*) * (newlines+1));
    *textfile = (char*)malloc(sizeof(char)*MAX_LINE_LEN);
    puts("Содержимое файла:");
    while((c = fgetc(fp)) != EOF) {
        if(c != '\n'){
            if(rid < MAX_LINE_LEN ) {
                *(*(textfile+newlines)+rid) = c;
                putc(c, stdout);
                rid++;
            }
        } else {
            *(*(textfile+newlines)+rid) = '\n';
            putc('\n', stdout);
            rid=0;
            newlines++;
            textfile = (char**)realloc(textfile, sizeof(char*) * (newlines+1));
            *(textfile+newlines) = (char*)malloc(sizeof(char) * MAX_LINE_LEN);
        }
    }

    words = countWords(*textfile);

    fp=freopen(NULL,"r",fp);

    double **matrix = (double**)calloc(newlines, sizeof(double*));
    for(int i=0; i < newlines; i++) *(matrix+i) = (double*)calloc(words, sizeof(double));
    parseMatrix(fp, matrix, newlines, words);
    replace7(matrix, newlines, words);
    printmx(matrix, newlines, words);

    fp=freopen(NULL,"w",fp);
    for(int i = 0; i < newlines; i++){
        for(int j = 0; j < words; j++){
            fprintf(fp, "%.lf ", *(*(matrix+i)+j));
        }
        fputc('\n', fp);
    }

    fclose(fp);
    for(int i=0; i < newlines; i++) free(*(matrix+i));
    for(int i=0; i < newlines; i++) free(*(textfile+i));
    free(matrix);
    free(textfile);
    return 0;
}

void replace7(double** mx, int rows, int cols){
    double max = findmxmax(mx, rows, cols, NULL, NULL, NULL);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            int element = (int) *(*(mx+i)+j);
            if(!(element%7)) *(*(mx+i)+j) = max;
        }
    }
}

void parseMatrix(FILE * file, double** mx, int rows, int cols){
    for(int i = 0, j = 0; i < rows; i++, j++){
      for(j = 0; j < cols; j++){
       if (!fscanf(file, "%lf", &mx[i][j]))
           break;
       printf("%lf\n", mx[i][j]);
       }
    }
}

