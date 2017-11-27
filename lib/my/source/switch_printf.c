/*
** EPITECH PROJECT, 2017
** switch_printf.c
** File description:
** switch of my_printf
*/

#include "stdyo.h"

int printfswitchsec(const char *format, int x, va_list list)
{
	switch (format[x]) {
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

int printfswitchone(const char *format, int x, va_list list)
{
	switch (format[x]) {
		case 'u':
			my_unsigned_putnbr(va_arg(list, unsigned int));
			return (x);
		case 'o':
			octalconvert(va_arg(list, unsigned int));
			return (x);
		case 'b':
			binaryconvert(va_arg(list, unsigned int));
			return (x);
		case 'X':
			hexaconvert(va_arg(list, unsigned int));
			return (x);
		default:
			x = printfswitchsec(format, x, list);
			return (x);
	}
	return (x);
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
		default:
			x = printfswitchone(format, x, list);
			return (x);
	}
	return (x);
}
