/*
** EPITECH PROJECT, 2017
** permission.c
** File description:
** permission for usr grp and other.
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

void permiusr(struct stat *st, int i)
{
	if (st[i].st_mode & S_IRUSR)
		my_printf("r");
	else
		my_printf("-");
	if (st[i].st_mode & S_IWUSR)
		my_printf("w");
	else
		my_printf("-");
	if (st[i].st_mode & S_IXUSR)
		my_printf("x");
	else
		my_printf("-");
}

void permigroup(struct stat *st, int i)
{
	if (st[i].st_mode & S_IRGRP)
		my_printf("r");
	else
		my_printf("-");
	if (st[i].st_mode & S_IWGRP)
		my_printf("w");
	else
		my_printf("-");
	if (st[i].st_mode & S_IXGRP)
		my_printf("x");
	else
		my_printf("-");
}

void permiother(struct stat *st, int i)
{
	if (st[i].st_mode & S_IROTH)
		my_printf("r");
	else
		my_printf("-");
	if (st[i].st_mode & S_IWOTH)
		my_printf("w");
	else
		my_printf("-");
	if (st[i].st_mode & S_ISVTX)
		my_printf("T");
	else if (st[i].st_mode & S_IXOTH)
		my_printf("x");
	else
		my_printf("-");
}

int numberfile(int ac, char **av)
{
	DIR *dir;
	int x = 0;
	struct dirent *number = malloc(sizeof(struct dirent));

	if (ac == 1 || (ac == 2 && av[1][0] == '-' && av[1][1] == 'l'))
		dir = opendir("./");
	else if (ac == 2 && av[1][0] != '-' && av[1][1] != 'l')
		dir = opendir(av[1]);
	else if (ac == 3)
		dir = opendir(av[2]);
	while (number) {
		number = readdir(dir);
		x = x + 1;
	}
	closedir(dir);
	free(number);
	return (x);
}

void isdir(struct stat *st, int i)
{
	if ((S_IFMT & st[i].st_mode) == S_IFDIR)
		my_printf("d");
	else
		my_printf("-");
}
