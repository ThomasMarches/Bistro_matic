/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** tests_infinmod.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(test_infinmod, test_diff)
{
    params_t *pms;

    pms = make_struct_params("0123456789", "()+-*/%");
    cr_assert_str_eq(infinmod("10", "10", pms), "0");
    cr_assert_str_eq(infinmod("-10", "10", pms), "-0");
    cr_assert_str_eq(infinmod("-9", "-9", pms), "0");
    cr_assert_str_eq(infinmod("9999", "9999", pms), "0");
    cr_assert_str_eq(infinmod("0", "10", pms), "0");
    cr_assert_str_eq(infinmod("-0", "10", pms), "-0");
    cr_assert_str_eq(infinmod("10", "2", pms), "0");
    cr_assert_str_eq(infinmod("7", "3", pms), "1");
    cr_assert_str_eq(infinmod("7", "-3", pms), "-1");
    cr_assert_str_eq(infinmod("48", "10", pms), "8");
    cr_assert_str_eq(infinmod("48", "-10", pms), "-8");
    cr_assert_str_eq(infinmod("35782912", "3728", pms), "1568");
    cr_assert_str_eq(infinmod("32589365728903892",
    "123456789", pms), "99541196");
}