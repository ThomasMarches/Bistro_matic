##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC		=	$(wildcard *.c)

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) clean

$(NAME):
	gcc -c $(SRC) -I../../include
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all