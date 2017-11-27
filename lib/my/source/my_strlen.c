/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** counts and returns the number of characters found in the string passed as parameter.
*/

#include "stdyo.h"

int my_strlen(char const *str)
{
	int i = 0;
	while (str[i] != '\0') {
		i = i + 1;
	}
	return (i);
}
