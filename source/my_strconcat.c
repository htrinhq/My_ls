/*
** EPITECH PROJECT, 2017
** my_strconcat.c
** File description:
** my_strcpy and my_strconcat
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
