/*
** EPITECH PROJECT, 2017
** display.c
** File description:
** display the properties for -l
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>
#include "ls.h"

void timeputstr(char *str)
{
	int c = 4;

	while (c <= 15) {
		my_putchar(str[c]);
		c = c + 1;
	}
}

void spaceusr(struct stat *st, int i, max_t *max)
{
	int d = 0;
	int y = my_strlen(getpwuid(st[i].st_uid)->pw_name);

	if (y < max->usr)
		while (d < (max->usr - y)) {
			my_printf(" ");
			d = d + 1;
	}
}

void spacegrp(struct stat *st, int i, max_t *max)
{
	int d = 0;
	int y = my_strlen(getgrgid(st[i].st_gid)->gr_name);

	if (y < max->grp)
		while (d < (max->grp - y)) {
			my_printf(" ");
			d = d + 1;
	}
}

void spacelink(struct stat *st, int i, max_t *max)
{
	unsigned int y;
	unsigned int d = 0;

	y = st[i].st_nlink;
	while (y >= 1) {
		y = y / 10;
		d = d + 1;
	}
	if (d < max->link)
		while (d < max->link) {
			my_printf(" ");
			d = d + 1;
	}
}

void spacesize(struct stat *st, int i, max_t *max)
{
	long y;
	long d = 0;

	y = st[i].st_size;
	if (y == 0)
		d = d + 1;
	while (y >= 1) {
		y = y / 10;
		d = d + 1;
	}
	if (d < max->size)
		while (d < max->size) {
			my_printf(" ");
			d = d + 1;
	}
}
