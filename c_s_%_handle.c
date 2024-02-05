#include "main.h"

/**
 * buffwrite - write a string into the buffer
 * @str: string to be written into buffer
 * @buff: pointer to buffer
 * @bufpos: pointer to buffer index
 *
 * Return: 1 (SUCCESS), -1 (FAILURE)
 **/
int buffwrite(char *buff, char *str, int *bufpos)
{
	int i;

	if (str == NULL)
		return (-1);

	for (i = 0; str[i]; i++, *bufpos = *bufpos + 1)
		buff[*bufpos] = str[i];
	return (1);
}

/**
 * handle_c - Handles character specifier.
 * @args: character
 * @buff: pointer to buffer
 * @bufpos: pointer to buffer index
 *
 * Return: 1 (SUCCESS), -1 (FAIL)
 **/
int handle_c(va_list *args, char *buff, int *bufpos)
{
	int stat = 1;
	char c = (char)va_arg(*args, int);

	if (!c)
	{
		*bufpos = *bufpos + 1;
		return (-1);
	}
	buff[*bufpos] = c;
	*bufpos = *bufpos + 1;
	return (stat);
}

/**
 * handle_s - Handles string specifier
 * @args: character pointer
 * @buff: pointer to buffer
 * @bufpos: pointer to buffer index
 *
 * Return: 1 (SUCCESS), -1 (FAIL)
 **/
int handle_s(va_list *args, char *buff, int *bufpos)
{
	int stat;
	char *str = va_arg(*args, char *);

	if (str == NULL)
	{
		buffwrite(buff, "(null)", bufpos);
		return (-1);
	}
	stat = buffwrite(buff, str, bufpos);
	return (stat);
}
