##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	=	myftp

SRC	=	src/main.c	\
		src/get_next_line.c	\
		src/extract_parameter.c			\
		src/call_commands.c	\
		src/server_client.c	\
		src/trash.c	\
		src/accept_connection.c		\
		src/command/list.c			\
		src/command/stor.c		\
		src/command/cdup.c		\
		src/command/cwd.c		\
		src/command/delete.c		\
		src/command/pwd.c		\
		src/command/noop.c		\
		src/command/help.c		\
		src/command/user.c		\
		src/command/pass.c		\

OBJ	=	$(SRC:.c=.o)

CPPFLAGS=	-I./include

CC	=	gcc -Wall -Wextra -g3

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -g3 $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

