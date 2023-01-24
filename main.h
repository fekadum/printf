#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * struct printf - structure that prints varaious functions and symbols
 * @t: type
 * @f: function
 */

typedef struct printf
{
	char *t;
	int (*f)(va_list);
} printf_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list ar_list);
int print_string(va_list ar_list);
int print_int(va_list i);
int print_dec(va_list d);
int print_bin(va_list b);
int print_unsigned(va_list u);
int print_oct(va_list o);
int print_x(va_list x);
int print_X(va_list X);
int print_S(va_list S);
int print_p(va_list p);

#endif
