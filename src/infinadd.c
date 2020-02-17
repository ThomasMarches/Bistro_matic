/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** infinadd
*/

#include <my.h>
#include <stdlib.h>

digit_t *remove_zero(digit_t *output, params_t *pms)
{
    digit_t *tmp = output;

    while (tmp->next != NULL) {
        if (tmp->digit == '-') {
            tmp->next = (remove_zero(tmp->next, pms));
            return (tmp);
        }
        if (tmp->digit != pms->base[0])
            return (tmp);
        tmp = tmp->next;
    }
    return (tmp);
}

digit_t *make_diff(char *str1, char *str2, char sign, params_t *pms)
{
    digit_t *output = NULL;

    str1 = str1 + compute_start_int(str1);
    str2 = str2 + compute_start_int(str2);
    if (sign != '-')
        output = (compute_diff(str1, str2, pms));
    else {
        if (my_strlen(str1) > my_strlen(str2)) {
            output = (compute_diff(str1, str2, pms));
            output = add_sign(output);
        }
        else
            output = (compute_diff(str2, str1, pms));
    }
    return (output);
}

char *infinadd(char *str1, char *str2, char op, params_t *pms)
{
    digit_t *output = NULL;
    digit_t *tmp = NULL;
    char true_op = compute_true_op(str1, str2, op, pms);
    char sign = compute_sign(str1, str2, true_op, pms);
    char *str = NULL;

    if (true_op == '+')
        output = (compute_summ(str1, str2, pms));
    else {
        output = make_diff(str1, str2, sign, pms);
    }
    if (sign == '-' && (str1[0] != '-' || true_op == '+'))
        output = add_sign(output);
    tmp = remove_zero(output, pms);
    str = my_list_to_str(tmp, pms);
    output = my_free_list(output);
    return (str);
}

char *make_infinadd(char *nbr, const char **argv, char op, params_t *pms)
{
    char *nbr2 = NULL;
    char *result = NULL;

    nbr2 = parse_add(argv, pms);
    result = infinadd(nbr, nbr2, op, pms);
    free(nbr2);
    free(nbr);
    return (result);
}