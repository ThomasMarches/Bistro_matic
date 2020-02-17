/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** tests_error
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>
#include <bistromatic.h>

void redirect_all_stdout(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

Test(test_bistro_err, test_err_exp, .init = redirect_all_stdout)
{
    params_t *pms;

    pms = make_struct_params("0123456789", "()-+*/%");
    cr_assert_eq(compute_error_exp("42 +", pms), 84);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG, "");
    cr_assert_eq(compute_error("234 a 123", pms), 84);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG, "");
}

Test(test_bistro_err, test_other, .init = redirect_all_stdout)
{
    cr_assert_eq(check_other("0123456789", "()*/%"), 0);
    cr_assert_stdout_eq_str("", "");
    cr_assert_eq(check_other("0123456789", "()2-*/%"), 84);
    cr_assert_stdout_eq_str(SYNTAX_ERROR_MSG, "");
}