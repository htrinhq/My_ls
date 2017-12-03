/*
** EPITECH PROJECT, 2017
** maxima.c
** File description:
** maxima functions
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

void fillmax(max_t *max)
{
	max->grp = 0;
	max->usr = 0;
	max->size = 0;
	max->link = 0;
}

void change_maxlm(struct stat *st, max_t *max, unsigned int *lm, int i)
{
	if (my_strlen(getpwuid(st[i].st_uid)->pw_name) > max->usr)
	max->usr = my_strlen(getpwuid(st[i].st_uid)->pw_name);
	if (st[i].st_nlink > *lm)
	*lm = st[i].st_nlink;
}

void change_maxsm(struct stat *st, max_t *max, long *sm, int i)
{
	if (st[i].st_size > *sm)
		*sm = st[i].st_size;
	if (my_strlen(getgrgid(st[i].st_gid)->gr_name) > max->grp)
		max->grp = my_strlen(getgrgid(st[i].st_gid)->gr_name);
}

void define_max(max_t *max, unsigned int lm, long sm)
{
	while (sm > 0) {
		sm = sm / 10;
		max->size = max->size + 1;
	}
	while (lm > 0) {
		lm = lm / 10;
		max->link = max->link + 1;
	}
}

void maxima(struct dirent **result, char *path, struct stat *st, DIR *dir, max_t *max)
{
	char *f_max = malloc(sizeof(char) * (my_strlen(path) * 999));
	int i = 0;
	long sm = 0;
	unsigned int lm = 0;

	while (result[i]) {
		if (result[i]->d_name[0] != '.') {
			f_max = my_strconcat(f_max, path, result[i]->d_name);
			stat(f_max, &st[i]);
			change_maxsm(st, max, &sm, i);
			change_maxlm(st, max, &lm, i);
		}
		i = i + 1;
		result[i] = readdir(dir);
	}
	define_max(max, lm, sm);
	free(f_max);
}
