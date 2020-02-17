/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** tests_infinadd
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

void redirect_all_stdout(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

Test(infin_add_base, test_add)
{
    params_t *pms;

    pms = make_struct_params("0123456789", "()+-*/%");
    cr_assert_str_eq(infinadd("-2", "-2", '+', pms), "-4");
    cr_assert_str_eq(infinadd("10", "8", '+', pms), "18");

}

Test(infin_add_base, test_diff, .init = redirect_all_stdout)
{
    params_t *pms;

    pms = make_struct_params("0123456789", "()+-*/%");
    cr_assert_str_eq(infinadd("6", "10", '-', pms), "-4");
}