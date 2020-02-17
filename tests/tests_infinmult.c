/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** tests_infinmult
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(test_infinmult, test_diff)
{
    params_t *pms;

    pms = make_struct_params("0123456789", "()+-*/%");
    cr_assert_str_eq(infin_mult("0", "0", pms), "0");
    cr_assert_str_eq(infin_mult("10", "0", pms), "0");
    cr_assert_str_eq(infin_mult("10", "10", pms), "100");
    cr_assert_str_eq(infin_mult("-10", "10", pms), "-100");
    cr_assert_str_eq(infin_mult("-9", "-9", pms), "81");
    cr_assert_str_eq(infin_mult("9999", "9999", pms), "99980001");
    cr_assert_str_eq(infin_mult("0", "10", pms), "0");
    cr_assert_str_eq(infin_mult("-0", "50", pms), "-0");
    cr_assert_str_eq(infin_mult("50", "-0", pms), "-0");
    cr_assert_str_eq(infin_mult("10000", "10000", pms), "100000000");
    cr_assert_str_eq(infin_mult("-10000", "10000", pms), "-100000000");
    cr_assert_str_eq(infin_mult("3", "15", pms), "45");
    cr_assert_str_eq(infin_mult("150", "2", pms), "300");
    cr_assert_str_eq(infin_mult("10", "9876", pms), "98760");
    cr_assert_str_eq(infin_mult("1", "100000000", pms), "100000000");
    cr_assert_str_eq(infin_mult("1", "1", pms), "1");
}