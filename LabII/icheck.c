/**������� ����������� �������� �����.
�������, ����� ���� �� �������� � �����������, �� ����� ����� ��� � �������� ������� ������*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <float.h>

#define INVALID -1      /*������ ���������*/
#define NEGATIVE -1
#define INTEGER 10
#define REAL 0.1
#define POSITIVE 1
#define multiplier char

#define ERR_INVALID_CHARACTER 1     /*���� ������*/
#define ERR_INVALID_MINUS 2
#define ERR_INVALID_COMMA 3
#define ERR_INVALID_EXPONENT 4
#define ERR_INVALID_VALUE_EXPONENT 5


char allowed[14] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', ',', '.', 'e'}; /*������ ���������� ��������*/

double icheck(){
    int valueof(char);
    //char number[16];                                          /*�������� �����*/
    char s, minus = 0, error = 0, zap = 0, exponent = 0;    /*s - ����������� ������*/
    double value = 0, drob = 1;                             /*value - �������� �����; drob - ������� ������� �����*/
    multiplier sign = POSITIVE, sign_exponent = POSITIVE;   /*����� �������� � ����������*/
    int num_do_zap = 0, num_pos_zap = 0, step = 0, j = 0, it;   /*num_do_zap ���-�� ���� �� �������; num_pos_zap - �����; step - �������(�������� ����������); j -������ �������*/
    while (((s = getchar()) != '\n')&&(error == 0))         /*���� ����� ��������� ������� �� ������� enter, ������������ �� ������ ������*/
    //scanf("%[^\n]",number);
    //for(it = 0; it < (sizeof(number) / sizeof(char)); it++)
    {
        //s = number[it];
        int index = valueof(s);                             /*index - ������������� �������� ������� valueof*/
        if (index == INVALID)                               /*���� ������� ��� � ������� ���������� ��������, �� error ����� �������� ��� ������ ������������ ������*/
            error = ERR_INVALID_CHARACTER;
        else                                                /*����� ��������������� ����� ��� ������ � ���������� ������ ������ ����*/
            switch (allowed[index])
        {
        case '-':
            if (((num_do_zap == 0)||(exponent == 1))&&(minus == 0)) /*���� ��� ����� ����� � �������� ����� ��� ����������, �� error ���������� ��� ������ ������������ �����*/
            {
                if (num_do_zap == 0)            /*���� ����� ��� ����� �����, �� �������� �������� ����� ���� �����, ���� ����������*/
                    sign = NEGATIVE;
                else
                    sign_exponent = NEGATIVE;
                minus = 1;
            }
            else error = ERR_INVALID_MINUS;
            break;
        case ',':
        case '.':
            if ((zap == 0)&&(exponent == 0)&&(num_do_zap != 0)) /*���� ������� ���� ������� �� ����, ���� � ����������, ���� ��� ������ �������, �� error ������������� �������� ���� ������ ������������ �������*/
                zap = 1;
            else
                error = ERR_INVALID_COMMA;
            break;
        case 'e':
            if ((exponent != 0)||((zap == 0)&&(num_do_zap == 0))||((zap != 0)&&(num_pos_zap == 0))) /*���� ���� ���������� ��� ����� �������, ���� ����� ����� �������, ���� ��� �� ������ ���� ����������, ��  error ������������� �������� ���� ������ �������� ����������*/
                error = ERR_INVALID_EXPONENT;
            else
            {
                exponent = 1; /*���� ������� if'a �� �����������, �� minus ����������*/
                minus = 0;
            }
            break;
        default:        /*���� �������� �����*/
            if (exponent == 1)          /*���� ��� ���� ����������, �� "����������"(���������� �� 10 ������� �������� ������� � ������������ ����� �������� �����)*/
            {
                step *= INTEGER;
                step += s - '0';
                if (abs(step) > 307)    /*����� �� �������� double(��, � double ������������ ������� - abs(308), �� ��� �������� 1,7...e308, � ���� � ������ 308, �� ����� ���������, ��� 3e308 ���� ������ � double, � ��� �� ���)*/
                    error = ERR_INVALID_VALUE_EXPONENT;
            }
            else
                if (zap == 0)       /*���� ������� �� ����, �� ����� "����������" � ������������� ������� ���� �� �������*/
                {
                    value *= INTEGER;
                    value += s - '0';
                    num_do_zap ++;
                }
                else                /*���� ������� ����, �� ����� "���������� �����"(������� ������� ����� ������� �� 10, ���������� �� �������� ����� � ������������ � �����*/
                {
                    drob *= REAL;
                    value += drob * (s - '0');
                    num_pos_zap ++;
                }
        }
    }
    if (sign_exponent < 0)      /*����� ���������� � �������(����������)*/
        for(j; j < step; j++)
            value *= REAL;
    else
        for(j; j < step; j++)
            value *= INTEGER;
    value *= sign;              /*����� ������������� ����(�����, ���� ����)*/
    switch (error)              /*����� � ������������ � �������*/
    {
    case 0:                     /*0 - ��� ������*/
        printf("%g\n", value);
        break;
    case 1:
        printf("��� ����� ������������ ������\n");
        break;
    case 2:
        printf("��� ����� ������������ �����\n");
        break;
    case 3:
        printf("���� ������� ������������ �������(�����)\n");
        break;
    case 4:
        printf("���� ������� ������ ����� ����������\n");
        break;
    case 5:
        printf("����� �� �������� ���� double\n");
        break;
    }

    /*���� ������ ��������� ���������, ���������� ��������. � ��������� ������ - ������������ MAX_DOUBLE*/
    value = (error == 0) ? value : DBL_MAX;
    return value;
}

                                /*������� ���������� ���������� �� ��� ����� ������*/
int valueof(char c){             /*� ������� ��������� ������*/
    int a = INVALID;
    int i;

    /*���� ������ ����������, �� ������������ ��� ������ � �������; ���� ���, �� ������������ -1*/
    for(i = 0; i<14; ++i)
        if (c == allowed[i])
        {
            a = i;
            break;
        }
    return a;
}
