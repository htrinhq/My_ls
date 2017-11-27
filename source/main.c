/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main.c
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

int numberfile(int ac, char **av)
{
	DIR *dir;
	int x = 0;
	struct dirent *number = malloc(sizeof(struct dirent));

	if (ac == 1)
		dir = opendir("./");
	else
		dir = opendir(av[1]);
	while (number) {
		number = readdir(dir);
		x = x + 1;
	}
	closedir(dir);
	return (x);
}

void simpledisplay(struct dirent **result, DIR *dir)
{
	int i = 0;

	while (result[i]) {
		if (result[i]->d_name[0] != '.')
			my_printf("%s\n", result[i]->d_name);
		i = i + 1;
		result[i] = readdir(dir);
	}
}

int main(int ac, char **av)
{
	DIR *dir;
	int y = 0;
	int nbfile = numberfile(ac, av);
	struct dirent **result = malloc(sizeof(struct dirent) * nbfile);

	if (ac == 1) {
		dir = opendir("./");
		result[y] = readdir(dir);
		simpledisplay(result, dir);
		closedir(dir);
	} else {
		dir = opendir(av[1]);
		result[y] = readdir(dir);
		simpledisplay(result, dir);
		closedir(dir);
	}
	return (0);
}
