#include "main.h"

/**
 * handle_u - Handles unsigned int
 * @args: va_list argument
 * @buff: pointer to buffer
 * @bufpos: pointer to buffer index
 *
 * Return: 1 (SUCCESS)
 **/
int handle_u(va_list *args, char *buff, int *bufpos)
{
	unsigned int u = va_arg(*args, unsigned int);
	unsigned int temp = u, div = 1;
	int stat = 1, i = 0, j;

	while (temp > 0)
	{
		temp /= 10;
		i++;
	}
	for (j = 0; j < (i - 1); j++)
		div *= 10u;
	for (; div > 0; div /= 10, *bufpos = *bufpos + 1)
	{
		buff[*bufpos] = ((u / div) % 10) + '0';
	}
	return (stat);
}

/**
 * handle_o - Handles ocatal numbers
 * @args: va_list argument
 * @buff: pointer to buffer
 * @bufpos: pointer to buffer index
 *
 * Return: 1 (SUCCESS)
 **/
int handle_o(va_list *args, char *buff, int *bufpos)
{
	int count = 1;
	unsigned int o = va_arg(*args, unsigned int), base = 8;
	char _case = 'o';

	convbase(o, base, _case, buff, bufpos);
	return (count);
}

/**
 * handle_x - Handles hexadecimal numbers lowercase
 * @args: va_list argument
 * @buff: pointer to buffer
 * @bufpos: pointer to buffer index
 *
 * Return: 1 (SUCCESS)
 **/
int handle_x(va_list *args, char *buff, int *bufpos)
{
	unsigned int x = va_arg(*args, unsigned int), base = 16;
	int count = 1;
	char _case = 'x';

	convbase(x, base, _case, buff, bufpos);
	return (count);
}

/**
 * handle_X - Handles hexadecimal numbers uppercase
 * @args: va_list argument
 * @buff: pointer to buffer
 * @bufpos: pointer to buffer index
 *
 * Return: 1 (SUCCESS)
 **/
int handle_X(va_list *args, char *buff, int *bufpos)
{
	unsigned int X = va_arg(*args, unsigned int), base = 16;
	int count = 1;
	char _case = 'X';

	convbase(X, base, _case, buff, bufpos);
	return (count);
}
