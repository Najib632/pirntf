#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>


int _putchar(char c);
int _printf(const char *format, ...);

/**
 * struct format_s - format parser
 * @spec: format specifier
 * @handle: pointer to a function
 **/
typedef struct format_s
{
	char *spec;
	int (*handle)(va_list);
} format_t;

void error(char *str);
int (*get_fmt(char spec))(va_list);
int handle_c(va_list args);
int handle_s(va_list args);
int handle_d(va_list args);
int handle_b(va_list args);

#endif /*_MAIN_H_*/
