##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		= 	src/compute_base.c	\
			src/compute_diff.c	\
			src/compute_sign.c	\
			src/compute_summ.c	\
			src/evalexpr.c	\
			src/infinadd.c	\
			src/main.c	\
			src/infindiv.c \
			src/make_struct.c	\
			src/put_result.c	\
			src/infinmult.c	\
			src/compute_mult.c	\
			src/infinmod.c	\
			src/check_error.c	\
			src/check_expr.c	\
			src/check_ops.c	\

NAME	= calc

OBJ	=	$(SRC: .c=.o)

CFLAGS += -W -Wall -Wextra -pedantic

DEBUG += -W -Wall -Wextra -pedantic -g3

TEST	=	lib/my/test.c

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(SRC) -I./include -L./lib/my -lmy $(CFLAGS)

clean:
		rm -f lib/my/*.o
		rm -f *.o
		rm -f a.out

fclean: clean
		rm -f $(NAME)
		rm -f lib/my/libmy.a

test_fclean: clean
		make -C ./tests/ fclean

re: fclean all

debug:
		make -C lib/my
		gcc -o $(NAME) $(SRC) -L./lib/my -I./include -lmy $(DEBUG)

test_run:
		make -C ./tests/ test_run