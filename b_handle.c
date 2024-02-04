#include "main.h"

/**
 * _strlen - Counts the length of a string
 * @str: string
 *
 * Return: count of string
 **/
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
 * convbase - Conversts from one base to another
 * @b: the unsigned int argument is converted to base
 * @bs: base to convert to
 * @cs: character case (upper or lower)
 * @buf: pointer to buffer
 * @p: pointer to buffer position
 *
 * Return: Nothing.
 **/
void convbase(unsigned long int b, unsigned int bs, char cs, char *buf, int *p)
{
	int i = 0, j;
	unsigned long int temp = b, div = 1;

	while (temp > 0)
	{
		temp /= bs;
		i++;
	}
	for (j = 0; j < (i - 1); j++)
		div *= bs;
	if (cs >= 'a' && cs <= 'z')
	{
		for (; div > 0; div /= bs, *p = *p + 1)
		{
			buf[*p] =  ((b / div) % bs) > 9 ?
				(((b / div) % bs) - 10) + 'a' : (b / div) % bs + '0';
		}
	}
	else
	{
		for (; div > 0; div /= bs, *p = *p + 1)
		{
			buf[*p] = ((b / div) % bs) > 9 ?
				(((b / div) % bs) - 10) + 'A' : ((b / div) % bs) + '0';
		}
	}
}

/**
 * handle_b - Converts unsigned int to binary
 * @args: the unsigned int argument is converted to binary
 * @buff: pointer to buff
 * @bufpos: pointer to buff
 *
 * Return: 1 (SUCCESS)
 **/
int handle_b(va_list *args, char *buff, int *bufpos)
{
	int stat = 1;
	unsigned int dec = va_arg(*args, unsigned int);
	unsigned int base = 2;
	char _case = 'b';

	convbase(dec, base, _case, buff, bufpos);
	return (stat);
}
