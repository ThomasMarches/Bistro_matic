/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** check_ops
*/

#include <bistromatic.h>
#include <my.h>
#include <stdlib.h>

int compute_double_op(int i, char *expr, char *op)
{
    while (expr[i] == ' ')
        i++;
    if (expr[i] == op[4] || expr[i] == op[5] || expr[i] == op [6]) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_EXPR_ERR);
    }
    return (i);
}

void check_double_op(char *expr, char *op)
{
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == op[4] || expr[i] == op[5] || expr[i] == op [6])
            i = compute_double_op(i + 1, expr, op);
    }
}

void check_pre_bracket_op(char *expr, char *op, int i)
{
    int bool = 0;

    if (i < 0)
        return;
    while (expr[i] == ' ')
        i++;
    for (int j = 0; op[j] != '\0'; j++) {
        if (expr[i] == op[j])
            bool = 1;
    }
    if (bool == 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_EXPR_ERR);
    }
}

void check_nbr_after_op(char *expr, char *op, int i)
{
    char c = expr[i];

    if (c == op[0] || c == op[2] || c == op[3] || c == op[4] || c == op[5]\
    || c == op[6]) {
        i++;
        while (expr[i] == ' ')
            i++;
        if (expr[i] == op[1] || expr[i] == '\0') {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_EXPR_ERR);
        }
    }
}

void check_after_bracket_op(char *expr, char *op, int i)
{
    while (expr[i] == ' ')
        i++;
    if (expr[i] == op[4] || expr[i] == op[5] || expr[i] == op [6]) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_EXPR_ERR);
    }

}