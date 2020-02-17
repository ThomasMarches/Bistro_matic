/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** basex_to_base10
*/

#include <my.h>

int basex_to_base10(char c, char *base, int base_int)
{
    for (int i = 0; i < base_int; i++)
        if (base[i] == c)
            return (i);
    return (0);
}

int cmp_nbr_base(char *str1, char *str2, params_t *pms)
{
    int int1 = 0;
    int int2 = 0;

    str1 = str1 + compute_start_int(str1);
    str2 = str2 + compute_start_int(str2);
    for (int i = 0; str1[i] != '\0'; i++) {
        int1 = basex_to_base10(str1[i], pms->base, pms->base_int);
        int2 = basex_to_base10(str2[i], pms->base, pms->base_int);
        if (int1 - int2 != 0)
            return (int1 - int2);
    }
    return (0);
}