#include "main.h"
#include <stdio.h>

/**
 * _printf - A custom implementation of the printf function.
 * @format: character string.
 *
 * Return: number of characters printed (SUCCESS), -1 (FAILURE)
 **/
int _printf(const char *format, ...)
{
	int nc = 0, idx, bufpos = 0, stat;
	char *buff = malloc(BUF_SIZE * sizeof(char));
	va_list args;

	if (format == NULL || buff == NULL)
		return (-1);
	memset(buff, 0, BUF_SIZE);
	va_start(args, format);
	for (idx = 0; format[idx]; idx++)
	{
		if (format[idx] == '%' && format[idx + 1])
		{
			if (format[idx + 1] == '%')
			{
				buff[bufpos++] = '%';
			}
			else if (format[idx + 1] != '%')
			{
				stat = check_format(format[idx + 1], &args, buff, &bufpos);
				if (stat == 0)
				{
					buff[bufpos++] = '%';
					buff[bufpos++] = format[idx + 1];
				}
			}
			format++;
		}
		else if (format[idx] != '%')
			buff[bufpos++] = format[idx];
		else
			return (-1);
	}
	nc =  write(1, buff, bufpos);
	free(buff);
	va_end(args);
	return (nc);
}
