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

int numberfile(char **av)
{
	DIR *dir;
	int x = 0;
	struct dirent *number = malloc(sizeof(struct dirent));
	dir = opendir(av[1]);

	while (number) {
		number = readdir(dir);
		x = x + 1;
	}
	closedir(dir);
	return (x);
}

void display()
{

}

int main(int ac, char **av)
{
	DIR *dir;
	int y = 0;
	int nbfile = numberfile(av);
	struct dirent **result = malloc(sizeof(struct dirent) * nbfile);

	if (ac == 1) {
		dir = opendir("./");
		result[y] = readdir(dir);
		display();
		closedir("./");
	}
	return (0);
}
