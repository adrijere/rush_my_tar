##
## Makefile for Makefile in /home/mathon_j/rendu/rush_my_tar/etape_1
## 
## Made by Jérémy MATHON
## Login   <mathon_j@epitech.net>
## 
## Started on  Sat Nov 30 11:59:14 2013 Jérémy MATHON
## Last update Sat Nov 30 17:56:15 2013 Jérémy MATHON
##

SRC=		my_archive.c

CC=		gcc

CFLAGS=		-g

NAME=		my_archive

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -rvf $(OBJ)

fclean:		clean
	@rm -rvf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
