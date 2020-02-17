/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** tests_infindiv
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(test_infindiv, test_diff)
{
    params_t *pms;

    pms = make_struct_params("0123456789", "()+-*/%");
    cr_assert_str_eq(infindiv("100", "10", pms), "10");
    cr_assert_str_eq(infindiv("10", "2", pms), "05");
    cr_assert_str_eq(infindiv("10", "3", pms), "03");
    cr_assert_str_eq(infindiv("-10", "10", pms), "-1");
    cr_assert_str_eq(infindiv("10", "-1", pms), "-10");
    cr_assert_str_eq(infindiv("1", "1", pms), "1");
    cr_assert_str_eq(infindiv("999", "333", pms), "3");
    cr_assert_str_eq(infindiv("50", "10", pms), "5");
    cr_assert_str_eq(infindiv("10000000", "50", pms), "0200000");
    cr_assert_str_eq(infindiv("100000000000000000000000000000000", \
"50", pms), "02000000000000000000000000000000");
    cr_assert_str_eq(infindiv("44444", "-4", pms), "-11111");
    cr_assert_str_eq(infindiv("-10000", "9", pms), "-01111");
}