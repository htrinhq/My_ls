/*
** EPITECH PROJECT, 2017
** getnumbers.c
** File description:
** getnumbers
*/

#include "stdyo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

short my_short_putnbr(short nb)
{
	if (nb >= 0 && nb <= 9) {
		my_putchar('0' + nb);
		return (0);
	} else {
		my_short_putnbr(nb / 10);
		my_short_putnbr(nb % 10);
	}
	return (0);
}

long my_long_putnbr(long nb)
{
	if (nb >= 0 && nb <= 9) {
		my_putchar('0' + nb);
		return (0);
	} else {
		my_long_putnbr(nb / 10);
		my_long_putnbr(nb % 10);
	}
	return (0);
}

long long my_longlong_putnbr(long long nb)
{
	if (nb >= 0 && nb <= 9) {
		my_putchar('0' + nb);
		return (0);
	} else {
		my_longlong_putnbr(nb / 10);
		my_longlong_putnbr(nb % 10);
	}
	return (0);
}
