/*
** EPITECH PROJECT, 2020
** main
** File description:
** Made by Vincent Daribo
*/

#include"includes/bsq.h"

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);

    if (fd == -1)
        return (84);
    if (ac != 2)
        return (84);
    if (check_errors(av[1]) == 84)
        return (84);
    bsq(av[1]);
    return (0);
}
