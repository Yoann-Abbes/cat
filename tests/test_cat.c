/*
** EPITECH PROJECT, 2018
** testcat
** File description:
** testcat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <criterion/criterion.h>
#include <errno.h>

int my_cat(int, char**);
int read_files(int, char**);

Test(test, my_cat)
{
    char *av[2] = {"./cat", "cat.c"};
    cr_assert(my_cat(2, av) == 0);
}

Test(test_multiple1, my_cat_multiple1)
{
    char *av[4] = {"./cat", "../cat/cat.c", "../cat/main.c", "../cat/Makefile"};
    cr_assert(my_cat(4, av) == 0);
}

Test(test_multiple2, my_cat_multiple2)
{
    char *av[4] = {"./cat", "cat.c", "main.c", "Makefile"};
    cr_assert(my_cat(4, av) == 0);
}

Test(test, my_cat_empy)
{
    char **av = NULL;
    cr_assert(my_cat(0, av) == 84);
}

Test(testac, my_cat_empyac)
{
    char *av[4] = {"./cat", "cat.c", "main.c", "Makefile"};
    cr_assert(my_cat(-2, av) == 84);
}

Test(test_multiple_err1, my_cat_multiple_err)
{
    char *av[4] = {"./cat", "Makef", "cat.c", "lol.c"};
    cr_assert(my_cat(4, av) != 0);
}

Test(test_multiple_err2, my_cat_multiple_err)
{
    char *av[2] = {"./cat", "../lib"};
    cr_assert(my_cat(4, av) != 0);
}

Test(test_multiple_err, my_cat_multiple_err)
{
    char *av[4] = {"./cat", "Makef", "cat.c", "lol.c"};
    cr_assert(my_cat(4, av) != 0);
}
