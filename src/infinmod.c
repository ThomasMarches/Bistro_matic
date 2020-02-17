/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** infinmod.c
*/

#include <my.h>
#include <unistd.h>
#include <stdlib.h>

char *infinmod(char *str, char *str2, params_t *pms)
{
    char *result = NULL;
    char *result2 = NULL;
    char *result3 = NULL;
    char sign = 0;

    result = infindiv(str, str2, pms);
    sign = result[0];
    result2 = infin_mult(result, str2, pms);
    free(result);
    result3 = infinadd(str, result2, '-', pms);
    free(result2);
    if (sign == '-' && result3[0] != '-')
        result3 = my_strcat("-", result3);
    return (result3);
}