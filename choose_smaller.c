/*
** EPITECH PROJECT, 2021
** choose the smaller number
** File description:
** MAde by Vincent Daribo
*/
#include<stdio.h>

int order_check(int *list)
{
    int i = 1;

    while (i < 3) {
        if (list[i] < list[i - 1])
            return (1);
        i++;
    }
    return 0;
}

int *swap(int *arr, int i1, int i2)
{
    int tmp;

    tmp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = tmp;
    return (arr);
}

int find_smaller(int a, int b, int c)
{
    int list[] = {a, b, c};
    int i = 0;

    while (order_check(list) != 0)
        for (i = 1; i < 3; i++)
            (list[i] <= list[i - 1]) ? swap(list, i, i - 1) : list;
    return (list[0]);
}

int find_bigger(int **list, int nbr_case, int nbr_col)
{
    int bigger = 0;

    for (int i = 0; i < nbr_case; i++)
        for (int j = 0; j < nbr_col; j++)
            if (list[i][j] > bigger)
                bigger = list[i][j];
    return (bigger);
}
