/*
** EPITECH PROJECT, 2017
** my_putchar.C
** File description:
** Write a given character
*/

#include <unistd.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}
