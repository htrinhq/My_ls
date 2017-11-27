/*
** EPITECH PROJECT, 2017
** longshortswitch.c
** File description:
** long and short switches and diese switch
*/

#include "stdyo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int dieseswitch (const char *format, int x, va_list list)
{
	switch (format[x]) {
		case 'o':
			my_putchar('0');
			octalconvert(va_arg(list, unsigned int));
			return (x);
		case 'x':
			my_putstr("0x");
			bighexaconvert(va_arg(list, unsigned int));
			return (x);
		case 'X':
			my_putstr("0X");
			hexaconvert(va_arg(list, unsigned int));
			return (x);
	}
	return (x);
}

int longlongswitch(const char *format, int x, va_list list)
{
	switch (format[x]) {
		case 'd':
		case 'i':
			my_longlong_putnbr(va_arg(list, long long));
			return (x);
		case 'u':
			my_ulonglong_putnbr(va_arg(list, unsigned long long));
			return (x);
	}
	return (x);
}

int longswitch(const char *format, int x, va_list list)
{
	switch (format[x]) {
		case 'd':
		case 'i':
			my_long_putnbr(va_arg(list, long));
			return (x);
		case 'u':
			my_ulong_putnbr(va_arg(list, unsigned long));
			return (x);
		case 'l':
			x = x + 1;
			x = longlongswitch(format, x, list);
		return (x);
	}
	return (x);
}

int shortswitch(const char *format, int x, va_list list)
{
	switch (format[x]) {
		case 'd':
		case 'i':
			my_short_putnbr(va_arg(list, int));
			return (x);
		case 'u':
			my_ushort_putnbr(va_arg(list, unsigned int));
			return (x);
		case 'h':
			x = x + 1;
			x = shortshortswitch(format, x, list);
		return (x);
	}
	return (x);
}

int shortshortswitch(const char *format, int x, va_list list)
{
	switch (format[x]) {
		case 'd':
		case 'i':
			my_put_nbr(va_arg(list, int));
			return (x);
		case 'u':
			my_put_nbr(va_arg(list, unsigned int));
			return (x);
	}
	return (x);
}
