/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <bistromatic.h>
#include <my.h>

static char *get_expr(unsigned int size)
{
    char *expr = NULL;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (!expr) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = '\0';
    return (expr);
}

void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

int main(int ac, char **av)
{
    unsigned int size = 0;
    char *expr = NULL;
    char *str = NULL;
    params_t *params_s = NULL;

    check_error(ac, av);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    check_expr(expr, av);
    params_s = make_struct_params(av[1], av[2]);
    str = eval_expr(expr, params_s);
    put_result(str, params_s);
    free(params_s);
    free(expr);
    return (EXIT_SUCCESS);
}