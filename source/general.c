/*
** EPITECH PROJECT, 2017
** general.c
** File description:
** general functions for display (simple and -l)
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

void properties(struct stat *st, int i, struct dirent **result, max_t *max)
{
	isdir(st, i);
	permiusr(st, i);
	permigroup(st, i);
	permiother(st, i);
	my_printf(".");
	spacelink(st, i, max);
	my_printf(" %d", st[i].st_nlink);
	my_printf(" %s", getpwuid(st[i].st_uid)->pw_name);
	spaceusr(st, i, max);
	my_printf(" %s", getgrgid(st[i].st_gid)->gr_name);
	spacegrp(st, i, max);
	spacesize(st, i, max);
	my_printf(" %lu ", st[i].st_size);
	timeputstr(ctime(&st[i].st_mtime));
	my_printf(" %s\n", result[i]->d_name);
}

void ldisplaymul(struct dirent **result, DIR *dir, char *path, struct stat *st)
{
	int i = 0;
	max_t *max = malloc(sizeof(max_t));
	char *fname = malloc(sizeof(char) * 999);

	fillmax(max);
	maxima(result, path, st, dir, max);
	dir = opendir(path);
	while (result[i]) {
		if (result[i]->d_name[0] != '.') {
			fname = my_strconcat(fname, path, result[i]->d_name);
			stat(fname, &st[i]);
			properties(st, i, result, max);
		}
		i = i + 1;
		result[i] = readdir(dir);
	}
	free(fname);
	free(max);
}

void ldisplay(struct dirent **result, DIR *dir, char *path, struct stat *st)
{
	int i = 0;
	max_t *max = malloc(sizeof(max_t));

	fillmax(max);
	maxima(result, "./", st, dir, max);
	dir = opendir("./");
	result[i] = readdir(dir);
	while (result[i]) {
		if (result[i]->d_name[0] != '.') {
			path = my_strconcat(path, "./", result[i]->d_name);
			stat(path, &st[i]);
			properties(st, i, result, max);
		}
		i = i + 1;
		result[i] = readdir(dir);
	}
	closedir(dir);
	free(max);
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
