/*
** EPITECH PROJECT, 2018
** mycat Yoann ABBES
** File description:
** mycat Yoann ABBES
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "my.h"

int read_files(int, char**, int);
void print_error(char*);

int my_cat(int ac, char **av)
{
    int retread = 1;
    char buff[30000];

    if (av == NULL)
        return (84);
    else if (ac < 1)
        return (84);
    if (ac == 1) {
        for (buff[0]='\0'; retread > 0; retread = read(0, buff, 300000))
            write(1, buff, retread);
        return (0);
    }
    else
        return (read_files(ac, av, 1));
}

int read_files(int ac, char **av, int i)
{
    int fd;
    int error = 0;
    int retread = 0;
    char buff[30000];

    buff[0] = '\0';
    for (; i < ac; i++) {
        fd = open(av[i], O_RDONLY);
        if (fd < 0) {
            print_error(av[i]);
            error = 84;
        }
        retread = read(fd, buff, 30000);
        if (retread < 0) {
            print_error(av[i]);
            error = 84;
        } else
            write(1, buff, retread);
    }
    close(fd);
    return (error);
}

void print_error(char *s)
{
    if (errno == 2) {
        write(2, "cat: ", 5);
        write(2, s, my_strlen(s));
        write(2, ": No such file or directory\n", 28);
    }
    if (errno == 21) {
        write(2, "cat: ", 5);
        write(2, s, my_strlen(s));
        write(2, ": Is a directory\n", 17);
    }
}
