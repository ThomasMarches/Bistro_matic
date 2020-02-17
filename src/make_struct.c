/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** make_struct
*/

#include <my.h>
#include <stdlib.h>

params_t *make_struct_params(char *base, char *op)
{
    params_t *params_struct = NULL;

    params_struct = malloc(sizeof(params_t));
    params_struct->base = base;
    params_struct->base_int = my_strlen(base);
    params_struct->op1 = op[0];
    params_struct->op2 = op[1];
    params_struct->op3 = op[2];
    params_struct->op4 = op[3];
    params_struct->op5 = op[4];
    params_struct->op6 = op[5];
    params_struct->op7 = op[6];
    return (params_struct);
}