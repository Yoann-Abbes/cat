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

int my_cat(int, char**);

int main(int ac, char **av)
{
    return (my_cat(ac, av));
}
