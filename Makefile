##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## libmy.a
##

SRC	=	src/main.c	\
		src/find.c	\
		src/manage_map.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

CFLAGS	=	-Wall -Wextra

all:	MAKEMAIN

MAKEMAIN:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -O3 -Ofast -march=native

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all
