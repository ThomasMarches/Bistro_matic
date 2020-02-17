/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** subject_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(subject_test, subject_test)
{
    params_t *pms = NULL;
    params_t *pms2 = NULL;
    params_t *pms3 = NULL;

    pms = make_struct_params("0123456789", "()+-*/%");
    pms2 = make_struct_params("0123456789", "{}vwxyz");
    pms3 = make_struct_params("0A@!;ie&]", "()+-*/%");

    cr_assert_str_eq(eval_expr("3+6", pms), "9");
    cr_assert_str_eq(eval_expr("3v6", pms2), "9");
    cr_assert_str_eq(eval_expr("----++-6*12", pms), "-72");
    cr_assert_str_eq(eval_expr("-(12-(4*32))", pms), "0116");
    cr_assert_str_eq(eval_expr("-(e@-(;*!@))", pms3), "0ee");
    cr_assert_str_eq(eval_expr("-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-\
20)/43)*20)*(-(12-98*42)*(16+63-50/3))", pms), "-744629760");
}