/*
** EPITECH PROJECT, 2021
** int array conversion
** File description:
** Made By Vincent Daribo
*/

#include"includes/bsq.h"

int **my_int_array(char **arr)
{
    int arr_len = my_arrlen(arr);
    int str_len = my_strlen(arr[0]);
    int **int_array = malloc(sizeof(int *) * (arr_len + 1));
    int i = 0;
    int j = 0;

    int_array[arr_len] = NULL;
    for (i = 0; i != arr_len + 1; i++)
        int_array[i] = malloc(sizeof(int) * str_len);
    for (i = 0; arr[i] != NULL; i++)
        for (j = 0; arr[i][j]; j++) {
            if (arr[i][j] == '.')
                int_array[i][j] = 1;
            else
                int_array[i][j] = 0;
        }
    return (int_array);
}

void destroy_int_arr(int **arr, int nbr_case)
{
    for (int i = 0; i < nbr_case; i++)
        free(arr[i]);
    free(arr);
}
