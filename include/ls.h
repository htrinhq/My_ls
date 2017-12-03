/*
** EPITECH PROJECT, 2017
** ls.h
** File description:
** ls
*/

#ifndef _LS_H
#define _LS_H

struct max {
        unsigned int link;
        long size;
        int usr;
        int grp;
};

typedef struct max max_t;
int my_printf(const char *format, ...);
int my_strlen(char const *str);
void my_putchar(char c);
void permiusr(struct stat *st, int i);
void permigroup(struct stat *st, int i);
void permiother(struct stat *st, int i);
int numberfile(int ac, char **av);
void isdir(struct stat *st, int i);
void timeputstr(char *str);
void spaceusr(struct stat *st, int i, max_t *max);
void spacegrp(struct stat *st, int i, max_t *max);
void spacelink(struct stat *st, int i, max_t *max);
void spacesize(struct stat *st, int i, max_t *max);
void properties(struct stat *st, int i, struct dirent **result, max_t *max);
void ldisplaymul(struct dirent **result, DIR *dir, char *path, struct stat *st);
void ldisplay(struct dirent **result, DIR *dir, char *path, struct stat *st);
void simpledisplay(struct dirent **result, DIR *dir);
char *my_strcpy(char *dest, char *src);
char *my_strconcat(char *dest, char *str1, char *str2);
void maxima(struct dirent **result, char *path, struct stat *st, DIR *dir, max_t *max);
void fillmax(max_t *max);
void change_maxlm(struct stat *st, max_t *max, unsigned int *lm, int i);
void change_maxsm(struct stat *st, max_t *max, long *sm, int i);
void define_max(max_t *max, unsigned int lm, long sm);
void one_ac(int y, int nbfile);
void two_minl(int y, int nbfile);
void two_simple(char **av, int y, int nbfile);
void three_minl(char **av, int nbfile);
void above_three(int ac, char **av, int nbfile);

#endif
