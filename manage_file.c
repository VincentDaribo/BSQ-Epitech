/*
** EPITECH PROJECT, 2021
** open an manage a file
** File description:
** Made by Vincent Daribo
*/

#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

char *get_file_content(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buff;
    struct stat info;

    stat(filepath, &info);
    buff = malloc(sizeof(char) * (info.st_size));
    read(fd, buff, (info.st_size - 1));
    buff[info.st_size - 1] = 0;
    close(fd);
    return (buff);
}
