#include "main.h"

/**
 * dec_bin - Decimal to binary conversion
 * @b: the unsigned int argument is converted to binary
 * @len: character count
 *
 * Return: Nothing.
 **/
void dec_bin(unsigned int b, int *len)
{
	if ((b / 2) > 0)
	{
		dec_bin((b / 2), len);
	}
	*len += _putchar((b % 2) + '0');
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
	unsigned int dec = va_arg(args, unsigned int);

	dec_bin(dec, &count);
	return (count);
}
