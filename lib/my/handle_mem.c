/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** handle_free
*/

#include <my.h>
#include <bistromatic.h>
#include <stdlib.h>

digit_t *my_free_list(digit_t *output)
{
    digit_t *tmp = NULL;

    while (output)
    {
        tmp = output->next;
        free(output);
        output = tmp;
    }
    return (output);
}

void free_two_char(char *str1, char *str2)
{
    free(str1);
    free(str2);
}