/*
** EPITECH PROJECT, 2021
** one line on the array
** File description:
** Made by Vincent Daribo
*/

#include"includes/bsq.h"

int row(char **arr)
{
    int count = 0;
    int i = 0;

    for (i = 0; arr[0][i]; i++) {
        if (arr[0][i] == '.' && count == 0) {
            my_putchar('x');
            count = 1;
        }else
            my_putchar(arr[0][i]);
    }
    if (!arr[0][i])
        my_putstr("\n");
    return (0);
}

int column(char **arr)
{
    int i = 0;
    int count = 0;

    for (i = 0; arr[i]; i++)
        if (my_strlen(arr[i]) != 1)
            return (0);
    for (i = 0; arr[i]; i++) {
        if (arr[i][0] == '.' && count == 0) {
            my_putstr("x\n");
            count = 1;
        }else
            (arr[i + 1] != NULL) ? my_printf("%c\n", arr[i][0]) :
            my_printf("%c", arr[i][0]);
    }
    if (!arr[i])
        my_putstr("\n");
    return (1);
}

int one_line(char **arr)
{
    if (my_arrlen(arr) == 1) {
        row(arr);
        return (1);
    }
    if (my_arrlen(arr) > 1) {
        if (column(arr) == (1))
            return (1);
    }
    return (0);
}
