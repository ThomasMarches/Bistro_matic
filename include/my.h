/*
** EPITECH PROJECT, 2019
** my_header
** File description:
** my header
*/

#ifndef MY_H_
#define MY_H_

typedef struct digit {
    int digit;
    int exedent;
    struct digit *next;
} digit_t;

typedef struct params
{
    char *base;
    int base_int;
    char op1;
    char op2;
    char op3;
    char op4;
    char op5;
    char op6;
    char op7;
} params_t;

char *infindiv(char *, char *, params_t *);
char *my_strcpy(char *);
void my_putchar(char);
int my_putstr(char const *);
char *my_revstr(char *);
int my_strcmp(char const *, char const *);
int my_strlen(const char *);
digit_t *compute_summ(char *, char *, params_t *);
digit_t *compute_diff(char *, char *, params_t *);
void my_show_list(digit_t *);
char *infinadd(char *, char *, char, params_t *);
char compute_sign(char *, char *, char, params_t *);
int compute_error(int, char **);
int my_list_size(digit_t const *);
char *my_list_to_str(digit_t *, params_t *);
char *get_nbrbase_in_str(char const **, params_t *);
char *eval_expr(char const *, params_t *);
char *parse_add(char const **, params_t *);
char *parse_str(char const **, params_t *);
params_t *make_struct_params(char *, char *);
int basex_to_base10(char, char *, int);
digit_t *add_sign(digit_t *);
digit_t *add(int, digit_t *, params_t *);
int add_sym(char, char, int, params_t *);
int check_char_in_base(char, params_t *);
void put_result(char *, params_t *);
int my_getnbr(const char *);
int cmp_nbr_base(char *, char *, params_t *);
int compute_start_int(char *);
char compute_true_op(char *, char *, char, params_t *);
char *compute_mult(char *, char, params_t *, int);
char *infin_mult(char *, char *, params_t *);
char *infinmod(char *, char *, params_t *);
char *my_strcat(char *, char *);
digit_t *my_free_list(digit_t *);
void check_error(int, char **);
void check_ops(char const *);
void check_base(char const *);
void check_expr(char *, char **);
char compute_nbr_sign(char const **);
char *make_infinadd(char *, const char **, char, params_t *);
char *sign_str(char *, char, params_t *);
void check_double_op(char *, char *);
void check_pre_bracket_op(char *, char *, int);
void check_after_bracket_op(char *, char *, int);
void check_nbr_after_op(char *, char *, int);
void free_two_char(char *, char *);
#endif /* !MY_H_ */