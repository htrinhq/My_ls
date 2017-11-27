/*
** EPITECH PROJECT, 2017
** unsignedgetnbr.c
** File description:
** unsignedgetnbr
*/

#include "stdyo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

unsigned int my_unsigned_putnbr(unsigned int nb)
{
	if (nb <= 9) {
		my_putchar('0' + nb);
		return (0);
	} else {
		my_unsigned_putnbr(nb / 10);
		my_unsigned_putnbr(nb % 10);
	}
	return (0);
}

unsigned short my_ushort_putnbr(unsigned short nb)
{
	if (nb <= 9) {
		my_putchar('0' + nb);
		return (0);
	} else {
		my_ushort_putnbr(nb / 10);
		my_ushort_putnbr(nb % 10);
	}
	return (0);
}

unsigned long long my_ulonglong_putnbr(unsigned long long nb)
{
	if (nb <= 9) {
		my_putchar('0' + nb);
		return (0);
	} else {
		my_ulonglong_putnbr(nb / 10);
		my_ulonglong_putnbr(nb % 10);
	}
	return (0);
}

unsigned long  my_ulong_putnbr(unsigned long nb)
{
	if (nb <= 9) {
		my_putchar('0' + nb);
		return (0);
	} else {
		my_ulong_putnbr(nb / 10);
		my_ulong_putnbr(nb % 10);
	}
	return (0);
}
