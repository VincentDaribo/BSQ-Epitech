/*
** EPITECH PROJECT, 2021
** convert an array into a string
** File description:
** MAde by Vincent DAribo
*/

#include"includes/bsq.h"

void arr_to_str(char **arr)
{
    char *str;
    int i = 0;
    int j = 0;
    int k = 0;
    int nbr_char_tot = 0;

    for (i = 0; arr[i]; i++)
        nbr_char_tot += my_strlen(arr[i]);
    str = malloc(sizeof(char) * (nbr_char_tot + 1 + i));
    str[nbr_char_tot + i] = '\0';
    for (i = 0; arr[i]; i++) {
        for (j = 0; arr[i][j]; j++, k++)
            str[k] = arr[i][j];
        str[k] = '\n';
        k++;
    }
    write(1, str, my_strlen(str));
    free(str);
}
