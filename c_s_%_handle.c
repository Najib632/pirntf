#include "main.h"

/**
 * is_num_string - checks if a string is a number
 * @str: string to be checked
 *
 * Return: 0 (SUCCESS), 1 (FAILURE)
 **/
int is_num_string(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

/**
 * error - Prints error message
 * @str: error message
 *
 * Return: Nothing
 **/
void error(char *str)
{
	int i;

	for (i = 0; str[i]; ++i)
		_putchar(str[i]);
	_putchar('\n');
}

/**
 * handle_c - Handles character specifier.
 * @args: character
 *
 * Return: 1 (SUCCESS), -1 (FAIL)
 **/
int handle_c(va_list args)
{
	int stat;
	char c = (char)va_arg(args, int);

	if (!c)
	{
		error(" ");
		return (0);
	}
	stat = _putchar(c);
	return (stat);
}

/**
 * handle_s - Handles string specifier
 * @args: character pointer
 *
 * Return: Number of characters (SUCCESS), -1 (FAIL)
 **/
int handle_s(va_list args)
{
	int cnt;
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		error("(nil)");
		return (0);
	}
	for (cnt = 0; str[cnt]; ++cnt)
		_putchar(str[cnt]);
	return (cnt);
}
