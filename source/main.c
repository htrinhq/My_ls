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

int main(int ac, char **av)
{
	if (ac > 3)
		return (0);
	int y = 0;
	int nbfile = numberfile(ac, av);

	if (ac == 1) {
		one_ac(y, nbfile);
	} else if (ac >= 2){
		if (ac == 2 && av[1][0] == '-' && av[1][1] == 'l') {
			two_minl(y, nbfile);
		} else if (ac == 2 && av[1][0] != '-' && av[1][1] != 'l') {
			two_simple(av, y, nbfile);
		} else if (ac == 3 && av[1][0] == '-' && av[1][1] == 'l') {
			three_minl(av, nbfile);
		} else if (ac == 3 && av[1][0] != '-' && av[1][1] != 'l') {
			above_three(ac, av, nbfile);
		}
	}
	return (0);
}
