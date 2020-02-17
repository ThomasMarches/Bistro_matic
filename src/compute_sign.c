/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** compute_sign
*/

#include <my.h>
#include <stdlib.h>

char compute_true_op(char *s1, char *s2, char op, params_t *pms)
{
    if (op == pms->op3) {
        if ((s1[0] != '-' && s2[0] != '-') || (s1[0] == '-' && s2[0] == '-'))
            return ('+');
        else
            return ('-');
    } else {
        if ((s1[0] != '-' && s2[0] != '-') || (s1[0] == '-' && s2[0] == '-'))
            return ('-');
        else
            return ('+');
    }
}

int compute_start_int(char *str)
{
    int i = 0;

    while ((str[i] == '-' || str[i] == '+') && str[i] != '\0') {
        i++;
    }
    return (i);
}

char compute_sign_diff(char *str1, char *str2, char op, params_t *pms)
{
    int l1 = my_strlen(str1) - compute_start_int(str1);
    int l2 = my_strlen(str2) - compute_start_int(str2);
    int cmp = cmp_nbr_base(str1, str2, pms);

    if (l2 > l1) {
        if (op == pms->op4)
            return ('-');
        else
            return ('+');
    }
    if (l1 > l2) {
        if (str1[0] == '-')
            return ('-');
        else
            return ('+');
    }
    if (cmp < 0)
        return ('-');
    return ('+');
}

char compute_sign(char *str1, char *str2, char op, params_t *pms)
{
    if (op == pms->op3) {
        if (str1[0] == '-')
            return ('-');
        else
            return ('+');
    }
    if (op == pms->op4)
        return (compute_sign_diff(str1, str2, op, pms));
    if (op == pms->op5) {
        if ((str1[0] != '-' && str2[0] != '-')
            || (str1[0] == '-' && str2[0] == '-'))
            return ('+');
        else
            return ('-');
    }
    return ('+');
}

digit_t *add_sign(digit_t *ouput)
{
    digit_t *node = NULL;

    node = malloc(sizeof(digit_t));
    node->next = ouput;
    node->digit = '-';
    return (node);
}