/*
** EPITECH PROJECT, 2017
** my_putnbr.c
** File description:
** ===> printf()
*/

#include "stdyo.h"

int my_put_nbr(int nb)
{
	if (nb >= 0 && nb <= 9) {
		my_putchar('0' + nb);
		return (0);
	} if (nb < 0 && nb > -2147483648) {
		my_putchar('-');
		my_put_nbr(-nb);
	} else {
		my_put_nbr(nb / 10);
		my_put_nbr(nb % 10);
	}
	return (0);
}
