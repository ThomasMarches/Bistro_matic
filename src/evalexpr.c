/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** evalexpr
*/

#include "my.h"
#include <stdlib.h>

char *parse_number(char const **argv, params_t *pms)
{
    char *nbr = NULL;

    while (**argv == ' ')
        (*argv)++;
    if (**argv == pms->op1) {
        (*argv)++;
        nbr = (parse_str(argv, pms));
        while (**argv == ' ')
            (*argv)++;
        if (**argv == pms->op2)
            (*argv)++;
        return (nbr);
    }
    return (get_nbrbase_in_str(argv, pms));
}

char *parse_factor(char const **argv, char *nbr, char op, params_t *pms)
{
    char *nbr2 = NULL;
    char *result = NULL;
    char sign = 0;

    sign = compute_nbr_sign(argv);
    nbr2 = sign_str(parse_number(argv, pms), sign, pms);
    if (op == pms->op5)
        result = infin_mult(nbr, nbr2, pms);
    if (op == pms->op6)
        result = infindiv(nbr, nbr2, pms);
    if (op == pms->op7)
        result = infinmod(nbr, nbr2, pms);
    while (**argv == ' ')
        (*argv)++;
    op = **argv;
    if (op == pms->op5 || op == pms->op6 || op == pms->op7) {
        (*argv)++;
        result = (parse_factor(argv, result, op, pms));
    }
    free_two_char(nbr, nbr2);
    return (result);
}

char *parse_add(char const **argv, params_t *pms)
{
    char *nbr = NULL;
    char op = 0;

    nbr = parse_number(argv, pms);
    while (**argv == ' ')
        (*argv)++;
    if (**argv == '\0')
        return (nbr);
    op = **argv;
    if (op != pms->op3 && op != pms->op4 && op != pms->op2) {
        (*argv)++;
        return (parse_factor(argv, nbr, op, pms));
    }
    return (nbr);
}

char *parse_str(char const **argv, params_t *pms)
{
    char *nbr = NULL;
    char op = 0;
    char sign = 0;

    sign = compute_nbr_sign(argv);
    nbr = sign_str(parse_number(argv, pms), sign, pms);
    while (**argv != '\0' && **argv != pms->op2) {
        for (; **argv == ' '; (*argv)++);
        op = **argv;
        (*argv)++;
        if (op != pms->op3 && op != pms->op4)
            nbr = (parse_factor(argv, nbr, op, pms));
        else if (op == pms->op3 || op == pms->op4)
            nbr = make_infinadd(nbr, argv, op, pms);
    }
    return (nbr);
}

char *eval_expr(char const *str, params_t *pms)
{
    return (parse_str(&str, pms));
}