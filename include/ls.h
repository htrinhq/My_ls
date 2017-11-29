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

#endif
