/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** Made by Vincent Daribo
*/

#include"includes/bsq.h"

char *my_strcat(char *src, char *add)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + my_strlen(add) + 1));
    int i;
    int j;

    for (i = 0; src[i]; i++)
        str[i] = src[i];
    for (i, j = 0; add[j]; i++, j++)
        str[i] = add[j];
    str[i] = '\0';
    return (str);
}
