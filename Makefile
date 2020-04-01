##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	=	myftp

SRC		=	src/main.c				\
			src/master.c			\
			src/socker_manage.c		\


OBJ		=	$(SRC:.c=.o)


CPPFLAGS=	-I./include

CC		=	gcc -Wall -Wextra -g3

RM		=	rm -f

all:	nm

nm:		$(OBJ)
		$(CC) -g3 $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
