/*
** EPITECH PROJECT, 2021
** bsq header
** File description:
** Made By Vincent Daribo
*/

#include<stdlib.h>
#include<fcntl.h>
#include"my.h"

#ifndef BSQ_H
#define BSQ_H

typedef struct coordinates_s
{
    int beg_x;
    int beg_y;
    int end_x;
    int end_y;
}coordinates_t;

void arr_to_str(char **);

int check_errors(char *);

int one_line(char **);

int **my_int_array(char **);

int find_smaller(int, int, int);

int my_arrlen(char **);

int bsq(char *);

void destroy_arr(char **);

void destroy_int_arr(int **, int);

char *get_file_content(char *);

char **get_the_arr(char *);

int get_first_line(char *);

int conv_int(char *);

void my_put_tab(char **);

char **arg_to_arr(char *, char);

char *my_strcat(char *, char *);
#endif
