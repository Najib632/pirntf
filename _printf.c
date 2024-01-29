#include "main.h"

/**
 * _printf - A custom implementation of the printf function.
 * @format: character string.
 *
 * Return: number of characters printed
 **/
int _printf(const char *format, ...)
{
	int nc = 0, idx;
	va_list args;

	va_start(args, format);
	for (idx = 0; format && format[idx]; idx++)
	{
		if (format[idx] == '%')
		{
			if (format[idx + 1] == '%')
				nc += _putchar('%');
			else
				nc += get_fmt(format[idx + 1])(args);
			format++;
		}
		else
		{
			nc += _putchar(format[idx]);
		}
	}
	va_end(args);
	return (nc);
}
