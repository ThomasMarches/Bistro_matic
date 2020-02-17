/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** compute_mult
*/

#include <my.h>
#include <stdio.h>
#include <stdlib.h>

digit_t *mult(int summ, digit_t *output, params_t *pms)
{
    digit_t *current = NULL;

    current = malloc(sizeof(digit_t));
    current->next = output;
    current->exedent = 0;
    if (summ >= pms->base_int)
        for (; summ >= pms->base_int; summ = summ - pms->base_int)
            current->exedent = current->exedent + 1;
    else
        current->exedent = 0;
    current->digit = pms->base[summ];
    return (current);
}

int mult_sym(char char1, char char2, int exedent, params_t *pms)
{
    int int1 = basex_to_base10(char1, pms->base, pms->base_int);
    int int2 = basex_to_base10(char2, pms->base, pms->base_int);
    int summ = 0;

    summ = int1 * int2 + exedent;
    return (summ);
}

digit_t *add_zero_mult(digit_t *output, params_t *pms)
{
    digit_t *current = NULL;

    current = malloc(sizeof(digit_t));
    current->next = output;
    current->digit = pms->base[0];
    current->exedent = 0;
    return (current);
}

char *compute_mult(char *str1, char str2, params_t *pms, int counter)
{
    int exedent = 0;
    digit_t *output = NULL;
    char *str = NULL;

    output = NULL;
    for (; counter > 0; counter--)
        output = add_zero_mult(output, pms);
    for (int i = my_strlen(str1) - 1; i >= 0; i--) {
        output = mult(mult_sym(str1[i], str2, exedent, pms), output , pms);
        exedent = output->exedent;
    }
    if (exedent != 0)
        output = add(add_sym(pms->base[0], pms->base[0], exedent, pms),
                            output, pms);
    str = my_list_to_str(output, pms);
    my_free_list(output);
    return (str);
}