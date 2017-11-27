/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** reproduces printf function.
*/

#include "stdyo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int get_aligned_size(const char *format, int x)
{
	int result = 0;

		while (format[x] > '0' && format[x] <= '9') {
			result = result + (format[x] - 48);
			result = result * 10;
			x = x + 1;
		}
		result = result / 10;
		return (result);
}

int my_printf_switch(const char *format, int x, va_list list)
{
	switch (format[x]) {
		case 's':
			my_putstr(va_arg(list, char*));
			return (x);
		case 'd':
		case 'i':
			my_put_nbr(va_arg(list, int));
			return (x);
		case 'c':
			my_putchar(va_arg(list, int));
			return (x);
		case '%':
			my_putchar('%');
			return (x);
		case 'u':
			my_unsigned_putnbr(va_arg(list, unsigned int));
			return (x);
		case 'o':
			octalconvert(va_arg(list,unsigned int));
			return (x);
		case 'b':
			binaryconvert(va_arg(list,unsigned int));
			return (x);
		case 'X':
			hexaconvert(va_arg(list, unsigned int));
			return (x);
		case 'x':
			bighexaconvert(va_arg(list, unsigned int));
			return (x);
		case '#':
			x = x + 1;
			x = dieseswitch(format, x, list);
			return (x);
		case 'l':
			x = x + 1;
			x = longswitch(format, x, list);
			return (x);
		case 'h':
			x = x + 1;
			x = shortswitch(format, x, list);
			return (x);
	}
	return (x);
}

int erasenb(const char *format, int x)
{
	while (format[x] >= '0' && format[x] <= '9') {
		x = x + 1;
	}
	return (x);
}

int my_printf(const char *format, ...)
{
	int x = 0;
	va_list	list;

	va_start(list, format);
	while (format[x] != '\0') {
		if (format[x] == '%') {
			x = x + 1;
			x = my_printf_switch(format, x, list);
			x = x + 1;
		} else {
			my_putchar(format[x]);
			x = x + 1;
		}
	}
	va_end(list);
	return (0);
}
