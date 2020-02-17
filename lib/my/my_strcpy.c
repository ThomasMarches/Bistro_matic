/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** copies string to another
*/

#include <my.h>
#include <stdlib.h>

char *my_strcpy(char *src)
{
    int i = 0;
    char *dest = NULL;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (int j = 0; j != 2; j = j + 1)
        dest[j] = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}