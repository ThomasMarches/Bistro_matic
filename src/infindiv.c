/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** infindiv.c
*/

#include <my.h>
#include <bistromatic.h>
#include <stdlib.h>

void check_div_zero(char *str, char *str2, params_t *pms)
{
    char *tmp = infinadd(str, str2, pms->op4, pms);
    int cmp = my_strcmp(tmp, str);

    free(tmp);
    if (cmp == 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_DIV_ZERO);
    }
}

char *fill_string(char *str, char *str2, params_t *pms)
{
    int i1 = my_strlen(str2);
    int i2 = my_strlen(str);
    int i = 0;
    char *str3 = NULL;

    if (i1 > i2)
        return (str2);
    str3 = malloc(sizeof(char) * (i2 + 2));
    for (int j = 0; j != my_strlen(str) + 2; j = j + 1)
        str3[j] = 0;
    for (; i < i1; i++)
        str3[i] = str2[i];
    for (; i < i2; i++)
        str3[i] = pms->base[0];
    str3[i] = '\0';
    return (str3);
}

char *make_add_diff(char * str, char *str2, char op, params_t *pms)
{
    char *result = infinadd(str, str2, op, pms);

    free(str);
    return (result);
}

char *compute_div(char *str, char *str2, params_t *pms)
{
    char *result = NULL;
    int i3 = my_strlen(str2);
    int counter = my_strlen(str) - my_strlen(str2);
    int index = 0;
    char *str3 = my_strcpy(str);

    str2 = fill_string(str, str2, pms);
    result = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int j = 0; j != my_strlen(str) + 1; j = j + 1, result[j - 1] = 0);
    for (int i = 0; counter >= 0; counter--, index++, i = 0) {
        for (; str3[0] != '-'; i++)
            str3 = make_add_diff(str3, str2, pms->op4, pms);
        str3 = make_add_diff(str3, str2, pms->op3, pms);
        result[index] = pms->base[i - 1];
        str2[i3 + counter - 1] = '\0';
    }
    free(str3);
    free(str2);
    result[index] = '\0';
    return (result);
}

char *infindiv(char *str, char *str2, params_t *pms)
{
    char *str3 = NULL;
    char sign = 0;

    check_div_zero(str, str2, pms);
    sign = compute_sign(str, str2, pms->op5, pms);
    str = str + compute_start_int(str);
    str2 = str2 + compute_start_int(str2);
    if (my_strlen(str2) > my_strlen(str)) {
        str3 = malloc(sizeof(char) * 1 + 1);
        for (int j = 0; j != 2; j = j + 1)
            str3[j] = 0;
        str3[0] = pms->base[0];
        return (str3);
    }
    str3 = compute_div(str, str2, pms);
    if (sign == '-')
        str3 = my_strcat("-", str3);
    return (str3);
}
