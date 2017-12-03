/*
** EPITECH PROJECT, 2017
** arguments.c
** File description:
** functions that handle the differents possible arguments
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

void one_ac(int y, int nbfile)
{
	DIR *dir;
	struct dirent **result = malloc(sizeof(struct dirent) * nbfile * 999);

	dir = opendir("./");
	result[y] = readdir(dir);
	simpledisplay(result, dir);
	closedir(dir);
	free(result);
}

void two_minl(int y, int nbfile)
{
	DIR *dir;
	struct dirent **result = malloc(sizeof(struct dirent) * nbfile * 999);
	char *path = malloc(sizeof(char) * nbfile * 999);
	struct stat *st = malloc(sizeof(struct stat) * nbfile * 999);

	dir = opendir("./");
	result[y] = readdir(dir);
	ldisplay(result, dir, path, st);
	closedir(dir);
	free(path);
	free(result);
	free(st);
}

void two_simple(char **av, int y, int nbfile)
{
	DIR *dir;
	struct dirent **result = malloc(sizeof(struct dirent) * nbfile * 999);
	char *path = malloc(sizeof(char) * nbfile * 999);

	dir = opendir(av[1]);
	result[y] = readdir(dir);
	path = my_strconcat(path, av[1], "/");
	simpledisplay(result, dir);
	closedir(dir);
	free(path);
	free(result);
}

void three_minl(char **av, int nbfile)
{
	DIR *dir;
	struct dirent **result = malloc(sizeof(struct dirent) * nbfile * 999);
	char *path = malloc(sizeof(char) * nbfile * 999);
	struct stat *st = malloc(sizeof(struct stat) * nbfile * 999);

	dir = opendir(av[2]);
	result[0] = readdir(dir);
	path = my_strconcat(path, av[2], "/");
	ldisplaymul(result, dir, path, st);
	closedir(dir);
	free(path);
	free(result);
	free(st);
}

void above_three(int ac, char **av, int nbfile)
{
	DIR *dir;
	struct dirent **result = malloc(sizeof(struct dirent) * nbfile * 999);
	char *path = malloc(sizeof(char) * nbfile * 999);
	int p = 1;

	while (p < ac) {
		dir = opendir(av[p]);
		result[0] = readdir(dir);
		path = my_strconcat(path, av[p], "/");
		my_printf("%s :\n", path);
		simpledisplay(result, dir);
		if (p != ac - 1)
			my_printf("\n");
		closedir(dir);
		p = p + 1;
	}
	free(path);
	free(result);
}
