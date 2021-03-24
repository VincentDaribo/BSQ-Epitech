/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** Made by Vincent Daribo
*/

#include"includes/bsq.h"
#include <stdio.h>

int find_bigger(int **list, int nbr_case, int nbr_col);

int get_first_line(char *filepath)
{
    char *str = get_file_content(filepath);
    int i = 0;
    char *first_line;

    for (i = 0; str[i] != '\n'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (84);
    first_line = malloc((sizeof(char) * i) + 1);
    for (i = 0; str[i] != '\n'; i++)
        first_line[i] = str[i];
    i = conv_int(first_line);
    free(first_line);
    free(str);
    return (i);
}

char **get_the_arr(char *filepath)
{
    int i = 0;
    int j = 0;
    char *str = get_file_content(filepath);
    char *arr = NULL;
    char **the_arr;

    for (i = 0; str[i] != '\n'; i++);
    i++;
    for (j = i; str[j]; j++);
    arr = malloc(sizeof(char) * (j + 1));
    for (int loop = 0; loop != j + 1; loop++)
        arr[loop] = 0;
    for (j = i, i = 0;str[j] != '\0'; j++, i++)
        arr[i] = str[j];
    the_arr = arg_to_arr(arr, '\n');
    free(str);
    free(arr);
    return (the_arr);
}

coordinates_t find_the_bigger_square(int **arr, int nbr_case, int nbr_col)
{
    int bigger = 0;
    coordinates_t sq_coo;

    for (int i = 1; i < nbr_case; i++)
        for (int j = 1; j < nbr_col; j++)
            if (arr[i][j] > 0 && arr[i][j - 1] > 0 &&
                arr[i - 1][j] > 0 && arr[i - 1][j - 1] > 0)
                arr[i][j] = find_smaller(arr[i - 1][j],
                arr[i][j - 1], arr[i - 1][j - 1]) + 1;
    bigger = find_bigger(arr, nbr_case, nbr_col);
    for (int i = (nbr_case - 1); i >= 1; i--)
        for (int j = (nbr_col - 1); j >= 1; j--)
            if (arr[i][j] == bigger) {
                sq_coo.beg_x = j - (bigger - 1);
                sq_coo.beg_y = i - (bigger - 1);
                sq_coo.end_x = j;
                sq_coo.end_y = i;
            }
    return (sq_coo);
}

int bsq(char *str)
{
    char **char_arr = get_the_arr(str);
    int **arr = my_int_array(char_arr);
    int i = 0;
    int j = 0;
    int nbr_case = my_arrlen(char_arr);
    int nbr_col = my_strlen(char_arr[0]);
    coordinates_t bsq_coo = find_the_bigger_square(arr, nbr_case, nbr_col);

    if (one_line(char_arr) == 1)
        return (0);
    for (i = 0; i < nbr_case; i++)
        for (j = 0; j < nbr_col; j++)
            if (j >= bsq_coo.beg_x && j <= bsq_coo.end_x &&
                i >= bsq_coo.beg_y && i <= bsq_coo.end_y)
                char_arr[i][j] = 'x';
    arr_to_str(char_arr);
    destroy_arr(char_arr);
    destroy_int_arr(arr, nbr_case);
    return (0);
}
