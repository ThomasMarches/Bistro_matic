/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** fun_check_error.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <bistromatic.h>
#include <my.h>

void read_base_ops(char **av)
{
    int counter = 0;
    int i = 0;

    for (; av[1][counter] != '\0'; i++) {
        if (av[1][counter] == av[1][i]) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_BASE);
        }
        if (av[2][i] == '\0') {
            counter++;
            i = counter;
        }
    }
}

void read_op(char **av)
{
    int counter = 0;
    int i = 1;

    for (; av[2][counter] != '\0'; i++) {
        if (av[2][counter] == av[2][i]) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_OPS);
        }
        if (av[2][i] == '\0') {
            i = 1 + counter;
            counter++;
        }
    }
}

void read_base(char **av)
{
    int counter = 0;
    int i = 1;

    for (; av[1][counter] != '\0'; i++) {
        if (av[1][counter] == av[1][i]) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_BASE);
        }
        if (av[1][i] == '\0') {
            i = 1 + counter;
            counter++;
        }
    }
}

void check_arg(int ac, char **av)
{
    if ((ac == 2 && (av[1][0] == '-' && av[1][1] == 'h')) || ac != 4) {
        my_putstr("USAGE\n./calc base operators size_read\n\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("- base: all the symbols of the base\n");
        my_putstr("- operators: the symbols for the parentheses");
        my_putstr("and the 5 operators\n");
        my_putstr("- size_read: number of characters to be read\n");
        exit(EXIT_USAGE);
    }
}

void check_error(int ac, char **av)
{
    check_arg(ac, av);
    check_ops(av[2]);
    check_base(av[1]);
    check_base(av[1]);
    read_base(av);
    read_op(av);
}