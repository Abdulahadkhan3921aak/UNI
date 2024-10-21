##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	g++ -Wall -Wextra -g

RM	=	rm -f

NAME	=	3rdSemester

SRC	=	main.cpp	\
		Game.cpp	\
		GameManager.cpp	\
		TicTacToe.cpp

OBJ	=	$(SRC:.cpp=.o)

CFLAGS	+=	-I./

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lopengl32

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
