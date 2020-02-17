/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** my_list_size
*/

#include <stdio.h>
#include <my.h>

int my_list_size(digit_t const *begin)
{
    digit_t const *cursor = begin;
    int i = 0;

    while (cursor != NULL) {
        cursor = cursor->next;
        i++;
    }
    return (i);
}