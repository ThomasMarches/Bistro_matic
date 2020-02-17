/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** tests_bistro
*/

#include <criterion/criterion.h>
#include <my.h>

Test(bistro_add, test_addition)
{
    params_t *pms;

    pms = make_struct_params("0123456789", "()+-*/%");
    cr_assert_str_eq(eval_expr("2+2", pms), "4");
    cr_assert_str_eq(eval_expr("2-2", pms), "0");
    cr_assert_str_eq(eval_expr("2-4", pms), "-2");
    cr_assert_str_eq(eval_expr("6-10", pms), "-4");
    cr_assert_str_eq(eval_expr("-6-10", pms), "-16");
    cr_assert_str_eq(eval_expr("123456789+987654321", pms), "1111111110");
    cr_assert_str_eq(eval_expr("94720186532920+4383919364291", pms), \
                                "99104105897211");
    cr_assert_str_eq(eval_expr("946237924338-45673902719", pms), \
                                "900564021619");
    cr_assert_str_eq(eval_expr("-2317890735215 - 0", pms), "-2317890735215");
    cr_assert_str_eq(eval_expr("0+2", pms), "2");
}

Test(bistro_mult, test_multiplication)
{
    params_t *pms;

    pms = make_struct_params("0123456789", "()+-*/%");
    cr_assert_str_eq(eval_expr("2 * 2", pms), "4");
    cr_assert_str_eq(eval_expr("2 * -2", pms), "-4");
    cr_assert_str_eq(eval_expr("2 * -4", pms), "-8");
    cr_assert_str_eq(eval_expr("10*10", pms), "100");
    cr_assert_str_eq(eval_expr("10*3", pms), "30");
    cr_assert_str_eq(eval_expr("123456789*987654321", pms), \
                                "121932631112635269");
    cr_assert_str_eq(eval_expr("94720186532920*4383919364291", pms), \
                                "415245659930923585743959720");
    cr_assert_str_eq(eval_expr("946237924338*-45673902719", pms), \
                                "-43218378905242294475022");
    cr_assert_str_eq(eval_expr("-2317890735215 * -0", pms), "0");
    cr_assert_str_eq(eval_expr("0*2", pms), "0");
}

Test(bistro_div, test_division)
{
    params_t *pms;

    pms = make_struct_params("0123456789", "()+-*/%");
    cr_assert_str_eq(eval_expr("2 / 2", pms), "1");
    cr_assert_str_eq(eval_expr("2 / -2", pms), "-1");
    cr_assert_str_eq(eval_expr("2 / 4", pms), "0");
    cr_assert_str_eq(eval_expr("6/10", pms), "0");
    cr_assert_str_eq(eval_expr("-6/10", pms), "0");
    cr_assert_str_eq(eval_expr("123456789/987654321", pms), "0");
    cr_assert_str_eq(eval_expr("94720186532920/4383919364291", pms), "21");
    cr_assert_str_eq(eval_expr("946237924338/-45673902719", pms), "-20");
    cr_assert_str_eq(eval_expr("0/2", pms), "0");
}

Test(bistro_mod, test_modulo)
{
    params_t *pms;

    pms = make_struct_params("0123456789", "()+-*/%");
    cr_assert_str_eq(eval_expr("2 % 2", pms), "0");
    cr_assert_str_eq(eval_expr("2 % 4", pms), "2");
    cr_assert_str_eq(eval_expr("6%10", pms), "6");
    cr_assert_str_eq(eval_expr("123456789%987654321", pms), "123456789");
    cr_assert_str_eq(eval_expr("94720186532920%4383919364291", pms), \
                                "2657879882809");
    cr_assert_str_eq(eval_expr("-946237924338%45673902719", pms), \
                                "-32759869958");
    cr_assert_str_eq(eval_expr("0%2", pms), "0");
}

Test(bistro_base, test_binarie_base)
{
    params_t *pms;

    pms = make_struct_params("01", "()+-*/%");
    cr_assert_str_eq(eval_expr("0110001+0101", pms), "110110");
    cr_assert_str_eq(eval_expr("0110001*0101", pms), "11110101");
    cr_assert_str_eq(eval_expr("0110001*(-0101)", pms), "-11110101");
    cr_assert_str_eq(eval_expr("0110001/0101", pms), "1001");
}