/*
** EPITECH PROJECT, 2017
** my_printf_bootstrap.c
** File description:
** sum_stdarg + disp_stdarg
*/

#include "stdyo.h"
#include <stdarg.h>
#include <unistd.h>

int sum_stdarg(int i, int nb, ...)
{
	va_list list;
	int x = 0;

	va_start(list, nb);
	if (i > 1 || i < 0)
		return (84);
	else if (i == 0) {
		while (nb > 0) {
			x = x + va_arg(list, int);
			nb = nb - 1;
		}
		return (x);
	} else if (i == 1) {
		while (nb > 0) {
			x = x + my_strlen(va_arg(list, char*));
			nb = nb - 1;
		}
		return (x);
	}
	va_end(list);
	return (x);
}

int error(char const *s)
{
	int x = 0;

	while (s[x] != '\0') {
		if (s[x] == 'c' || s[x] == 'i' || s[x] == 's')
			x = x + 1;
		else
			return (1);
	}
	return (0);
}

int disp_stdarg(char *s, ...)
{
	va_list list;
	int x = 0;

	va_start(list, s);
	if (error(s))
		return (84);
	while (s[x] != '\0') {
		if (s[x] == 'i')
			my_put_nbr(va_arg(list, int));
		else if (s[x] == 'c')
			my_putchar(va_arg(list, int));
		else
			my_putstr(va_arg(list, char*));
		my_putchar('\n');
		x = x + 1;
	}
	va_end(list);
	return (0);
}
