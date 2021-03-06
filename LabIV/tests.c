#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "arrayutils.h"

/*tests*/
void test_ccheckit(void);
void test_cinsert(void);
void test_carelins(void);
void test_darelins(void);
void test_genrandom(void);
void test_dfillarran(void);

int main_tests(){
    test_dfillarran();
}

void test_dfillarran(){
    double* testarr = (double*)calloc(5, sizeof(double));
    dfillarran(testarr, 5);
    puts("array is:");
    for(int i = 0; i < 5; i++) printf("%.lf ", *(testarr + i));
    free(testarr);
}

void test_genrandom(){
    puts("2-digits: ");
    for(int i = 0; i < 20; i++) printf("%d ", genrandom(2));
    putchar('\n');
    puts("3-digits: ");
    for(int i = 0; i < 20; i++) printf("%d ", genrandom(3));
    putchar('\n');
    puts("5-digits: ");
    for(int i = 0; i < 20; i++) printf("%d ", genrandom(5));

}

void test_darelins(){
    double* double_kek = (double*)calloc(5, sizeof(double));
    darelins(double_kek, 5);
    putchar('\n');
    for(int i = 0; i < 5; i++) printf("%lf ", *(double_kek + i));
    free(double_kek);
}

void test_carelins(){
    char* kek = (char*)calloc(5, sizeof(char));
    carelins(kek, 5);
    putchar('\n');
    for(int i = 0; i < 5; i++) printf("%d ", *(kek + i));
    free(kek);
}

void test_cinsert(){
    double arr[20];
    printf("insert value:\n");
    for(int i = 0; i < 3; i++){
        char *row_data = (char*)calloc(32, sizeof(char));
        cinsert(row_data);
        arr[i] = dcheckit(row_data);
        if(errno != 0) {
            perror("kek:");
            i--;
        }
        free(row_data);
    }
}

void test_dcheckit(){
    /*TODO: write this func*/
}

void test_ccheckit(){
    char letter = 0, digit = 0;
    char *one_char = (char*)calloc(2, sizeof(char));
    char *c_seq = (char*)calloc(3, sizeof(char));  /*correct sequence*/
    char *ic_seq = (char*)calloc(3, sizeof(char)); /*incorrect sequence*/

    /*one char test*/
    *one_char = 'a';
    *(one_char + 1) = '\0';
    letter = ccheckit(one_char);
    if(errno != 0) perror("(!)");
    printf("Passing a letter, char:'%c', code:%d", letter, letter);

    /*correct sequence test*/
    *c_seq = '8';
    *(c_seq + 1) = '3';
    *(c_seq + 2) = '\0';
    digit = ccheckit(c_seq);
    if(errno != 0) perror("(!)");
    printf("\nPassing a correct digit, as a sequence\"%s\", got: %d", c_seq, digit);

    /*incorrect sequence test*/
    *ic_seq = 'a';
    *(ic_seq + 1) = '1';
    *(ic_seq + 2) = '\0';
    digit = ccheckit(ic_seq);
    if(errno != 0) perror("(!)");
    printf("\nPassing a unalowed sequence \"%s\", got:%d\n", ic_seq, digit);

    free(one_char);
    free(c_seq);
    free(ic_seq);
}
