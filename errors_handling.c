/*
** EPITECH PROJECT, 2021
** error handling file
** File description:
** MAde by Vincent Daribo
*/

#include"includes/bsq.h"

int check_errors(char *filepath)
{
    char *str = get_file_content(filepath);
    int nb_line = get_first_line(filepath);
    int i = 0;
    int count = 0;

    for (i = 0; str[i]; i++)
        if (str[i] == '\n')
            count++;
    if (count != nb_line) {
        return 84;
    }
    free(str);
    return 0;
}
