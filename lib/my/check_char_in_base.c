/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** check_char_in_base
*/

#include <my.h>

int check_char_in_base(char c, params_t *pms)
{
    for (int i = 0; i < pms->base_int; i++)
        if (c == pms->base[i])
            return (1);
    return (0);
}