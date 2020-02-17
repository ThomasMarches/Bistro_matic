/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** put_result
*/

#include <my.h>
#include <stdlib.h>

void put_result(char *str, params_t *pms)
{
    int bool = 0;
    char sign = 0;
    int i = 0;

    if (str[i] == '-') {
        i++;
        sign = '-';
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] != pms->base[0] && bool == 0) {
            my_putchar(sign);
            bool = 1;
        }
        if (bool != 0)
            my_putchar(str[i]);
        if (bool == 0 && str[i + 1] == '\0' && str[i] == pms->base[0])
            my_putchar(str[i]);
    }
    free(str);
    my_putchar('\n');
}