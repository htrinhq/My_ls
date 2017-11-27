##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	source/converters.c	\
		source/getnumbers.c	\
		source/hexaswitch.c	\
		source/longshortswitch.c	\
		source/my_evil_str.c	\
		source/my_printf_bootstrap.c	\
		source/my_printf.c	\
		source/my_putchar.c	\
		source/my_put_nbr.c	\
		source/my_putstr.c	\
		source/my_strlen.c	\
		source/unsignedgetnumber.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-W -Wall -Wextra -Werror -I include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

PHONY: fclean clean all re
