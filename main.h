#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1024

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
	int (*handle)(va_list, char *);
} format_t;

int is_num_string(const char *str);
void error(char *str);
void print_number(unsigned int n, char *len);
void convbase(unsigned int b, unsigned int base, char _case, char *buff);
int (*get_fmt(char spec))(va_list, char *);
int handle_c(va_list args, char *);
int handle_s(va_list args, char *);
int handle_d(va_list args, char *);
int handle_b(va_list args, char *);
int handle_u(va_list args, char *);
int handle_o(va_list args, char *);
int handle_x(va_list args, char *);
int handle_X(va_list args, char *);
int negreturn(va_list args, char *);
int fmterr(va_list args, char *);

#endif /*_MAIN_H_*/
