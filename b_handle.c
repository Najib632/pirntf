#include "main.h"

/**
 * argcnt - Count the number of arguments expected
 * @format: contains format for expected arguments
 *
 * Return: argument count (SUCCESS), -1 (FAILURE)
 **/
int argcnt(const char *format)
{
	int count = 0, i;

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
			continue;
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				format++;
				continue;
			}
			else
				count++;
		}
	}
	return (count);
}

/**
 * negreturn - Returns minus one
 * @args: unused variable
 *
 * Return: Always -1.
 **/
int negreturn(__attribute((unused))va_list args)
{
	error(" ");
	return (-1);
}

/**
 * fmterr - Return minus for argument error
 * @args: unused variable
 *
 * Return: Always -1.
 **/
int fmterr(__attribute((unused))va_list args)
{
	error("Error handling format specifier.");
	return (-1);
}

/**
 * convbase - Conversts from one base to another
 * @b: the unsigned int argument is converted to base
 * @base: base to convert to
 * @len: character count
 * @_case: character case (upper or lower)
 *
 * Return: Nothing.
 **/
void convbase(unsigned int b, unsigned int base, int *len, char _case)
{
	int rem;

	if ((b / base) > 0)
	{
		convbase((b / base), base, len, _case);
	}
	rem = b % base;
	if (_case >= 'a' && _case <= 'f')
		*len += _putchar((rem > 9) ? (rem - 10) + 'a' : rem + '0');
	else
		*len += _putchar((rem > 9) ? (rem - 10) + 'A' : rem + '0');
}

/**
 * handle_b - Converts unsigned int to binary
 * @args: the unsigned int argument is converted to binary
 *
 * Return: character count (SUCCESS), -1 (FAILURE)
 **/
int handle_b(va_list args)
{
	int count = 0;
	unsigned int dec = va_arg(args, unsigned int), base = 2;
	char _case = 'b';

	convbase(dec, base, &count, _case);
	return (count);
}
