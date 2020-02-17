/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_list_to_str
*/

#include <stdio.h>
#include <stdlib.h>
#include <my.h>

digit_t *start_list(digit_t *list, params_t *pms)
{
    digit_t *tmp = list;

    for (int i = 0; tmp != NULL; i++, tmp = tmp->next) {
        if (tmp->digit == pms->base[0] && tmp->next == NULL)
            return (tmp);
        else if (tmp->digit != pms->base[0])
            return (tmp);
    }
}

char *my_list_to_str(digit_t *list, params_t *pms)
{
    digit_t *tmp = list;
    int bool = 0;
    int len = 0;
    int start = 0;
    char *str = NULL;

    tmp = start_list(list, pms);
    len = my_list_size(tmp) + 1;
    str = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i != len + 1; i = i + 1)
    str[i] = 0;
    for (int i = 0; tmp != NULL; i++, tmp = tmp->next) {
        str[i] = tmp->digit;
    }
    return (str);
}