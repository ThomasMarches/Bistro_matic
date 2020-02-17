/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** check_expr
*/

#include <stdlib.h>
#include <my.h>
#include <bistromatic.h>

int check_chara_in_base(char expr, char *argv)
{
    int base = 0;

    for (int i = 0; argv[i] != '\0'; i++) {
        if (argv[i] != expr)
            base++;
    }
    return (base);
}

int check_chara_in_op(char expr, char *argv)
{
    int op = 0;

    for (int i = 0; argv[i] != '\0'; i++) {
        if (argv[i] != expr)
            op++;
    }
    return (op);
}

void check_bracket(char *expr, char *op)
{
    int open = 0;
    int close = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == op[0]) {
            check_pre_bracket_op(expr, op, i - 1);
            check_after_bracket_op(expr, op, i + 1);
            open += 1;
        }
        if (expr[i] == op[1])
            close += 1;
    }
    if (open - close != 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_EXPR_ERR);
    }
}

int check_first_char(char *expr, char *op)
{
    int i = 0;

    while (expr[i] == ' ')
        i++;
    if (expr[i] == op[4] || expr[i] == op[5] || expr[i] == op [6]) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_EXPR_ERR);
    }
    return (i);
}

void check_expr(char *expr, char **argv)
{
    int op = 0;
    int base = 0;
    int i = 0;
    int op_len = my_strlen(argv[2]);
    int base_len = my_strlen(argv[1]);

    i = check_first_char(expr, argv[2]);
    for (; expr[i] != '\0'; i++) {
        if (expr[i] != ' ') {
            op = check_chara_in_op(expr[i], argv[2]);
            base = check_chara_in_base(expr[i], argv[1]);
        }
        if (op + base == op_len + base_len) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_EXPR_ERR);
        }
        check_nbr_after_op(expr, argv[2], i);
    }
    check_bracket(expr, argv[2]);
    check_double_op(expr, argv[2]);
}