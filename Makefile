##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	source/main.c	\
		source/permission.c	\
		source/display.c	\
		source/general.c	\
		source/my_strconcat.c	\
		source/maxima.c	\
		source/arguments.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

CFLAGS	=	-W -Wall -Wextra -I include

LDFLAGS	=	-L ./lib/my -lmy

all:	libmake $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

libmake:
	make -C ./lib/my/

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my/

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./lib/my/

re:	fclean all

PHONY: fclean clean all re libmake
