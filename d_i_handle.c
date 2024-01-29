#include "main.h"

/**
 * print_number - Prints an int number
 * @n: number parameter
 * @len: length of number
 *
 * Return: Nothing.
 **/
void print_number(unsigned int n, int *len)
{
	if ((n / 10) > 0)
		print_number(n / 10, len);
	*len += _putchar((n % 10) + '0');
}

/**
 * handle_d - Handles int arguments
 * @args: int argument
 *
 * Return: no of integers
 **/
int handle_d(va_list args)
{
	int numlen = 0;
	int n = va_arg(args, int);
	unsigned int number;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		numlen++;
	}
	number = n;
	print_number(number, &numlen);
	return (numlen);
}
