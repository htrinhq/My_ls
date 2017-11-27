/*
** EPITECH PROJECT, 2017
** hexaswitch.c
** File description:
** bighexaswitch and hexaswitch
*/

#include "stdyo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void hexasecswitch(char *number, unsigned int retain, int o)
{
	switch (retain) {
		case 13:
			number[o] = 'D';
			break;
		case 14:
			number[o] = 'E';
			break;
		case 15:
			number[o] = 'F';
			break;
		default:
			number[o] = retain + 48;
			break;
	}
}

void hexaswitch(char *number, unsigned int retain, int o)
{
	switch (retain) {
		case 10:
			number[o] = 'A';
			break;
		case 11:
			number[o] = 'B';
			break;
		case 12:
			number[o] = 'C';
			break;
		default:
			hexasecswitch(number, retain, o);
			break;
	}
}

void bighexasecswitch(char *number, unsigned int retain, int o)
{
	switch (retain) {
		case 13:
			number[o] = 'd';
			break;
		case 14:
			number[o] = 'e';
			break;
		case 15:
			number[o] = 'f';
			break;
		default:
			number[o] = retain + 48;
			break;
	}
}

void bighexaswitch(char *number, unsigned int retain, int o)
{
	switch (retain) {
		case 10:
			number[o] = 'a';
			break;
		case 11:
			number[o] = 'b';
			break;
		case 12:
			number[o] = 'c';
			break;
		default:
			bighexasecswitch(number, retain, o);
			break;
	}
}
