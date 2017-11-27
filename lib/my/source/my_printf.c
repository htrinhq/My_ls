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
