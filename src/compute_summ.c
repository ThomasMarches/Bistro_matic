/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** compute_summ
*/

#include <my.h>
#include <stdio.h>
#include <stdlib.h>

digit_t *add(int summ, digit_t *output, params_t *pms)
{
    digit_t *current = NULL;
    int result = 0;

    current = malloc(sizeof(digit_t));
    current->next = output;
    if (summ >= pms->base_int)
        current->exedent = 1;
    else
        current->exedent = 0;
    result = summ - current->exedent * pms->base_int;
    current->digit = pms->base[result];
    return (current);
}

int add_sym(char char1, char char2, int exedent, params_t *pms)
{
    int int1 = basex_to_base10(char1, pms->base, pms->base_int);
    int int2 = basex_to_base10(char2, pms->base, pms->base_int);
    return (int1 + int2 + exedent);
}

digit_t *compute_summ(char *str1, char *str2, params_t *pms)
{
    int i = my_strlen(str1) - 1;
    int j = my_strlen(str2) - 1;
    int exedent = 0;
    digit_t *output = NULL;

    output = NULL;
    for (;i >= 0 && j >= 0; i--, j--, exedent = output->exedent)
        output = add(add_sym(str1[i], str2[j], exedent, pms), output, pms);
    for (;i >= 0; i--, exedent = output->exedent)
        output = add(add_sym(str1[i], '0', exedent, pms), output, pms);
    for (;j >= 0; j--, exedent = output->exedent)
        output = add(add_sym('0', str2[j], exedent, pms), output, pms);
    if (exedent != 0)
        output = add(add_sym('0', '0', exedent, pms), output, pms);
    return (output);
}