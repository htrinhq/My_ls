/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef STDYO_H_
#define STDYO_H_
#include <stdarg.h>

int my_put_nbr(int c);
void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
int sum_stdarg(int i, int nb, ...);
int error(char const *s);
int disp_stdarg(char *s, ...);
char  *my_evil_str(char *str);
int my_printf(const char *format, ...);
unsigned int my_unsigned_putnbr(unsigned int nb);
short my_short_putnbr(short nb);
unsigned short my_ushort_putnbr(unsigned short nb);
long my_long_putnbr(long nb);
long long my_longlong_putnbr(long long nb);
unsigned long long my_ulonglong_putnbr(unsigned long long nb);
unsigned long  my_ulong_putnbr(unsigned long nb);
void hexaconvert(unsigned int nb);
void octalconvert(unsigned int nb);
void bighexaconvert(unsigned int nb);
void binaryconvert(unsigned int nb);
int dieseswitch (const char *format, int x, va_list list);
int longlongswitch(const char *format, int x, va_list list);
int longswitch(const char *format, int x, va_list list);
int shortswitch(const char *format, int x,va_list list);
int shortshortswitch(const char *format, int x,va_list list);
void hexaswitch(char *number, unsigned int retain, int o);
void bighexaswitch(char *number, unsigned int retain, int o);

#endif
