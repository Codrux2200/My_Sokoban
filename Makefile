##
## EPITECH PROJECT, 2021
## B-PSU-101-TLS-1-1-minishell1-saad.berrada
## File description:
## Makefile
##

SRC     =      ./lib/my/sokoban.c			\
				./lib/my/my_putstr_err.c 	 	\
				./lib/my/gestion_colision.c 		\
				./lib/my/my_strlen.c 		\
				./lib/my/my_putstr.c 	 	\
				./lib/my/reduce_big_funtion.c 	 	\
				./lib/my/reduce_big_function_suite.c 	 	\
				./lib/my/check_defeat.c 	 	\
				./lib/my/test_x_colision.c 	 	\

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

NAME2	= 	./lib/my/my.h

all:	compil_lib compil_my

compil_lib:	$(OBJ)
		ar rc $(NAME) $(OBJ)

compil_my:
		cp $(NAME2) ./include
		gcc -lncurses -o my_sokoban main.c libmy.a


clean:
		rm -f $(OBJ)

fclean:	clean
		rm libmy.a
		rm include/my.h
		rm my_sokoban

re: fclean all