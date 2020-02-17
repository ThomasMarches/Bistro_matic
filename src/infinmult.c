/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** infinmult.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <my.h>

char *add_line(char *str, char *str2, char op, params_t *pms)
{
    char *result = infinadd(str, str2, op, pms);

    free(str);
    free(str2);
    return (result);
}

char *infin_mult(char *str1, char *str2, params_t *pms)
{
    char **lines = NULL;
    char *result = NULL;
    char sign = '+';
    int counter = 0;
    int i = my_strlen(str2) - 1;
    int len_str2 = my_strlen(str2);

    sign = compute_sign(str1, str2, '*', pms);
    lines = malloc(sizeof(char *) * (my_strlen(str2) + 1));
    for (int j = 0; j != my_strlen(str2) + 1; j = j + 1)
        lines[j] = NULL;
    for (; i >= 0; i--, counter++)
        lines[counter] = compute_mult(str1, str2[i], pms, counter);
    result = lines[0];
    for (i = 1; i < len_str2; i++)
        result = add_line(result, lines[i], pms->op3, pms);
    if (sign == '-')
        result = my_strcat("-", result);
    free(lines);
    return (result);
}