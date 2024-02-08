#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

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
	int (*handle)(va_list *, char *, int *);
} format_t;

int _strlen(char *str);
int buffwrite(char *buff, char *str, int *bufpos);
int is_num_string(const char *str);
int check_format(char spec, va_list *args, char *buff, int *bufpos);
void print_number(unsigned int n, char *buff, int *bufpos);
void convbase(unsigned long int, unsigned int, char, char *, int *);
int (*get_fmt(char spec))(va_list *, char *, int *);
int check_size(char *, int);
int handle_c(va_list *args, char *, int *);
int handle_s(va_list *args, char *, int *);
int handle_d(va_list *args, char *, int *);
int handle_b(va_list *args, char *, int *);
int handle_u(va_list *args, char *, int *);
int handle_o(va_list *args, char *, int *);
int handle_x(va_list *args, char *, int *);
int handle_X(va_list *args, char *, int *);
int handle_S(va_list *args, char *, int *);
int handle_p(va_list *args, char *, int *);

#endif /*_MAIN_H_*/
