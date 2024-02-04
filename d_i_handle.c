#include "main.h"

/**
 * print_number - write a number into buffer
 * @n: number to write
 * @buff: pointer to buffer
 * @bufpos: buffer position
 *
 * Return: Nothing
 */
void print_number(unsigned int n, char *buff, int *bufpos)
{
	int i = 0, init = *bufpos;
	unsigned int temp = n;

	while (temp > 0)
	{
		temp /= 10;
		i++;
	}
	*bufpos = *bufpos + i;
	for (; i > 0; i--)
	{
		buff[init + i - 1] = (n % 10) + '0';
		n /= 10;
	}
}

/**
 * handle_d - Handles int arguments
 * @args: int argument
 * @buff: pointer to buff
 * @bufpos: pointer to buffer position
 *
 * Return: 1 (SUCCESS), -1 (FAILURE)
 **/
int handle_d(va_list *args, char *buff, int *bufpos)
{
	int stat = 1;
	int n = va_arg(*args, int);

	if (n < 0)
	{
		buff[*bufpos] = '-';
		*bufpos = *bufpos + 1;
		n = -n;
	}
	print_number(n, buff, bufpos);
	return (stat);
}
