#include "main.h"

/**
 * _printf - A custom implementation of the printf function.
 * @format: character string.
 *
 * Return: number of characters printed
 **/
int _printf(const char *format, ...)
{
	int nc = 0, idx, stat;
	char buff[BUF_SIZE];
	va_list args;

	if (format == NULL)
	{
		error("empty format string!");
		return (0);
	}
	va_start(args, format);
	for (idx = 0; format[idx]; idx++)
	{
		if (format[idx] == '%')
		{
			if (format[idx + 1] == '%')
			{
				buff[idx] = '%';
			}
			else
			{
				stat = get_fmt(format[idx + 1])(args, buff);
				if (stat < 0)
					return (0);
				nc += stat;
			}
			format++;
		}
		else
		{
			buff[idx] = format[idx];
		}
	}
	va_end(args);
	return (nc);
}
