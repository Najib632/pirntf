#include "main.h"

/**
 * handle_d - Handles int arguments
 * @args: int argument
 *
 * Return: no of integers
 **/
int handle_d(va_list args)
{
	int stat, numlen = 0;
	int n = va_arg(args, int);
	int number = n;

	if (n < 0)
	{
		stat = _putchar('-');
		n = -n;
		numlen++;
	}
	for (; (number / 10) > 0; ++numlen, number = number / 10)
		_putchar((number % 10) + '0');

	return (numlen);
}
