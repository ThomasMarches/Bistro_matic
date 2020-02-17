##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		= 	../src/compute_base.c	\
			../src/compute_diff.c	\
			../src/compute_sign.c	\
			../src/compute_summ.c	\
			../src/evalexpr.c	\
			../src/infinadd.c	\
			../src/make_struct.c	\
			../src/put_result.c	\
			../src/infinmult.c	\
			../src/compute_mult.c	\
			../src/infindiv.c	\
			../src/infinmod.c	\

TEST_SRC	=	tests_bistro.c	\
				tests_infinadd.c	\
				tests_infinmult.c	\
				tests_infindiv.c	\
				tests_infinmod.c	\
				subject_tests.c	\

NAME	= unit_test

OBJ		=	$(SRC: .c=.o)

LIB		= -L../lib/my -lmy
CFLAGS += --coverage -lcriterion --verbose -lgcov

test_run:	$(NAME) clean

$(NAME):	$(OBJ)
	make -C ../lib/my
	gcc -o unit_tests $(SRC) $(TEST_SRC) $(LIB) -I../include $(CFLAGS)
	./unit_tests

fclean: clean
		rm -f $(NAME)
		rm -f ../lib/my/libmy.a
		rm -f *.o
		rm -f ../lib/my/*.o

clean:
		rm -f *.gcda
		rm -f *.gcno
		rm -f *.c.gcov

re: fclean test_run