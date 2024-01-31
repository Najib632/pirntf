#include "main.h"

/**
 * print_number - Prints an int number
 * @n: number parameter
 * @len: length of number
 *
 * Return: Nothing.
 **/
void print_number(unsigned int n, char *len)
{
	if ((n / 10) > 0)
		print_number(n / 10, len + 1);
	*len = _putchar((n % 10) + '0');
}

/**
 * handle_d - Handles int arguments
 * @args: int argument
 * @buff: pointer to buff
 *
 * Return: no of integers
 **/
int handle_d(va_list args, char *buff)
{
	int numlen = 0;
	int n = va_arg(args, int);
	unsigned int number;

	if (n < 0)
	{
		*buff++ = '-';
		n = -n;
	}
	number = n;
	print_number(number, buff);
	return (numlen);
}
