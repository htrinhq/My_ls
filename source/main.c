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

char *my_strcpy(char *dest, char *src)
{
	int x = 0;

	while (src[x] != '\0') {
		dest[x] = src[x];
		x = x + 1;
	}
	dest[x] = '\0';
	return (dest);
}

char *my_strconcat(char *dest, char *str1, char *str2)
{
	int i = my_strlen(str1);
	int x = 0;

	my_strcpy(dest, str1);
	while (str2[x] != '\0') {
		dest[i] = str2[x];
		i = i + 1;
		x = x + 1;
	}
	dest[i] = '\0';
	return (dest);
}

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
	//free(number);
	return (x);
}

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
	if (st[i].st_mode & S_IXOTH)
		my_printf("x");
	else
		my_printf("-");
}

void isdir(struct stat *st, int i)
{
	if ((S_IFMT & st[i].st_mode) == S_IFDIR)
		my_printf("d");
	else
		my_printf("-");
}

void timeputstr(char *str)
{
	int c = 4;

	while (c <= 15) {
		my_putchar(str[c]);
		c = c + 1;
	}
}

void spacegrp(struct stat *st, int i, max_t *max)
{
	int d = 0;
	int y = my_strlen(getgrgid(st[i].st_gid)->gr_name);

	//y = st[i].st_nlink;
	/*while (y >= 1) {
		y = y / 10;
		d = d + 1;
	}*/
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
	my_printf(" %s", getgrgid(st[i].st_gid)->gr_name);
	spacegrp(st, i, max);
	spacesize(st, i, max);
	my_printf(" %lu ", st[i].st_size);
	timeputstr(ctime(&st[i].st_mtime));
	my_printf(" %s\n", result[i]->d_name);
}

unsigned int linkmax(struct dirent **result, char *path, struct stat *st, DIR *dir)
{
	char *f_max = malloc(sizeof(char) * (my_strlen(path) * 2));
	int i = 0;
	unsigned int x = 0;
	int link = 1;

	while (result[i]) {
		if (result[i]->d_name[0] != '.') {
			//f_max = malloc(sizeof(char) * (my_strlen(path) + my_strlen(result[i]->d_name)));
			f_max = my_strconcat(f_max, path, result[i]->d_name);
			stat(f_max, &st[i]);
			if (st[i].st_nlink > x)
				x = st[i].st_nlink;
		}
		i = i + 1;
		result[i] = readdir(dir);
	}
	while (x > 0) {
		x = x / 10;
		link = link + 1;
	}
	//free(f_max);
	return (link);
}

int grpmax(struct dirent **result, char *path, struct stat *st, DIR *dir)
{
	char *f_max = malloc(sizeof(char) * (my_strlen(path) * 2));
	int i = 0;
	int x = 0;

	while (result[i]) {
		f_max = my_strconcat(f_max, path, result[i]->d_name);
		stat(f_max, &st[i]);
		if (my_strlen(getgrgid(st[i].st_gid)->gr_name) > x)
			x = my_strlen(getgrgid(st[i].st_gid)->gr_name);
		i = i + 1;
		result[i] = readdir(dir);
	}
	free(f_max);
	return (x);
}

long sizmax(struct dirent **result, char *path, struct stat *st, DIR *dir)
{
	char *f_max = malloc(sizeof(char) * (my_strlen(path) * 2));
	int i = 0;
	long x = 0;
	long size = 0;

	while (result[i]) {
		if (result[i]->d_name[0] != '.') {
			f_max = my_strconcat(f_max, path, result[i]->d_name);
			stat(f_max, &st[i]);
			if (st[i].st_size > x)
				x = st[i].st_size;
		}
		i = i + 1;
		result[i] = readdir(dir);
	}
	while (x > 0) {
		x = x / 10;
		size = size + 1;
	}
	free(f_max);
	return (size);
}

void ldisplaymult(struct dirent **result, DIR *dir, char *path, struct stat *st)
{
	int i = 0;
	max_t *max = malloc(sizeof(max_t));
	char *fname = malloc(sizeof(char) * my_strlen(path));

	max->size = sizmax(result, path, st, dir);
	max->link = linkmax(result, path, st, dir);
	max->grp = grpmax(result, path, st, dir);
	//my_printf("grp : %d\n", max->grp);
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

	max->size = sizmax(result, path, st, dir);
	max->link = linkmax(result, path, st, dir);
	dir = opendir("./");
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


int main(int ac, char **av)
{
	DIR *dir;
	int y = 0;
	int nbfile = numberfile(ac, av);
	struct dirent **result = malloc(sizeof(struct dirent) * nbfile);
	struct stat *st = malloc(sizeof(struct stat) * nbfile);
	char *path = malloc(sizeof(char) * nbfile);

	if (ac == 1) {
		dir = opendir("./");
		result[y] = readdir(dir);
		ldisplay(result, dir, path, st);
		//simpledisplay(result, dir);
		closedir(dir);
	} else {
		dir = opendir(av[1]);
		result[y] = readdir(dir);
		path = my_strconcat(path, av[1], "/");
		ldisplaymult(result, dir, path, st);
		//simpledisplay(result, dir);
		closedir(dir);
	}
	free(st);
	free(path);
	free(result);
	return (0);
}
