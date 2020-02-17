/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** my_atoi
*/

#include <my.h>
#include <stdlib.h>

char *sign_str(char *str, char sign, params_t *pms)
{
    if (str[0] == '-')
        if (sign == '-')
            str[0] = pms->base[0];
        else
            return (str);
    else if (sign == '-')
        return (my_strcat("-", str));
    return (str);
}

char compute_nbr_sign(char const **str)
{
    int i = 0;

    for (; **str == '-' || **str == '+'; (*str)++) {
        if (**str == '-')
            i++;
    }
    if (i % 2 == 0)
        return ('+');
    else
        return ('-');
}

char *get_nbrbase_in_str(char const **str, params_t *pms)
{
    char *nbr = NULL;
    int bool = 0;
    int len = 0;
    char sign = '+';

    sign = compute_nbr_sign(str);
    while (*(*str + len) != '\0' && check_char_in_base(*(*str + len), pms)) {
        while (**str == ' ')
            (*str)++;
        len++;
    }
    nbr = malloc(sizeof(char) * len + 1);
    for (int i = 0; i != len + 1; i = i + 1)
        nbr[i] = 0;
    for (int i = 0; i < len; i++, (*str)++) {
        nbr[i] = **str;
    }
    if (sign == '-')
        return (my_strcat("-", nbr));
    return (nbr);
}