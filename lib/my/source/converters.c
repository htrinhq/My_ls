/*
** EPITECH PROJECT, 2017
** converters.c
** File description:
** converters about octal, binary and hexa
*/

#include "stdyo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void octalconvert(unsigned int nb)
{
	char *number = malloc(sizeof(char) * 32);
	int o = 0;

	while (nb >= 1) {
		number[o] = (nb % 8) + 48;
		nb = nb / 8;
		o = o + 1;
	}
	my_evil_str(number);
	my_putstr(number);
}

void hexaconvert(unsigned int nb)
{
	char *number = malloc(sizeof(char) * 32);
	unsigned int retain = 0;
	int o = 0;

	while (nb >= 1) {
		retain = nb % 16;
		hexaswitch(number, retain, o);
		nb = nb / 16;
		o = o + 1;
	}
	my_evil_str(number);
	my_putstr(number);
}

void bighexaconvert(unsigned int nb)
{
	char *number = malloc(sizeof(char) * 32);
	unsigned int retain = 0;
	int o = 0;

	while (nb >= 1) {
		retain = nb % 16;
		bighexaswitch(number, retain, o);
		nb = nb / 16;
		o = o + 1;
	}
	my_evil_str(number);
	my_putstr(number);
}

void binaryconvert(unsigned int nb)
{
	char *number = malloc(sizeof(char) * 32);
	int o = 0;


	while (nb >= 1) {
		number[o] = (nb % 2) + 48;
		nb = nb / 2;
		o = o + 1;
	}
	my_evil_str(number);
	my_putstr(number);
}
