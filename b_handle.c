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
 * @buff: pointer to buff
 *
 * Return: Always -1.
 **/
int negreturn(__attribute((unused))va_list args, char *buff)
{
	error("Not expecting an argument.");
	return (-1);
}

/**
 * fmterr - Return minus for argument error
 * @args: unused variable
 * @buff: pointer to buff
 *
 * Return: Always -1.
 **/
int fmterr(__attribute((unused))va_list args, char *buff)
{
	error("Error handling format specifier.");
	return (-1);
}

/**
 * convbase - Conversts from one base to another
 * @b: the unsigned int argument is converted to base
 * @base: base to convert to
 * @_case: character case (upper or lower)
 * @buff: pointer to buffer
 *
 * Return: Nothing.
 **/
void convbase(unsigned int b, unsigned int base, char _case, char *buff)
{
	int rem;

	if ((b / base) > 0)
	{
		convbase((b / base), base, _case, buff);
	}
	rem = b % base;
	if (_case >= 'a' && _case <= 'f')
		*buff++ = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
	else
		*buff++ = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
}

/**
 * handle_b - Converts unsigned int to binary
 * @args: the unsigned int argument is converted to binary
 * @buff: pointer to buff
 *
 * Return: character count (SUCCESS), -1 (FAILURE)
 **/
int handle_b(va_list args, char *buff)
{
	int count;
	unsigned int dec = va_arg(args, unsigned int), base = 2;
	char _case = 'b';

	convbase(dec, base, _case, buff);
	for (count = 0; (dec / base) > 0u; count++)
		;
	return (count);
}
