#include "main.h"

/**
 * handle_u - Handles unsigned int
 * @args: va_list argument
 *
 * Return: character count (SUCCESS), -1 (FAILURE)
 **/
int handle_u(va_list args)
{
	unsigned int u = va_arg(args, unsigned int);
	int count = 0;

	print_number(u, &count);
	return (count);
}

/**
 * handle_o - Handles ocatal numbers
 * @args: va_list argument
 *
 * Return: character count (SUCCESS), -1 (FAILURE)
 **/
int handle_o(va_list args)
{
	int count = 0;
	unsigned int o = va_arg(args, unsigned int), base = 8;
	char _case = 'o';

	convbase(o, base, &count, _case);
	return (count);
}

/**
 * handle_x - Handles hexadecimal numbers lowercase
 * @args: va_list argument
 *
 * Return: character count (SUCCESS), -1 (FAILURE)
 **/
int handle_x(va_list args)
{
	unsigned int x = va_arg(args, unsigned int), base = 16;
	int count = 0;
	char _case = 'x';

	convbase(x, base, &count, _case);
	return (count);
}

/**
 * handle_X - Handles hexadecimal numbers uppercase
 * @args: va_list argument
 *
 * Return: character count (SUCCESS), -1 (FAILURE)
 **/
int handle_X(va_list args)
{
	unsigned int X = va_arg(args, unsigned int), base = 16;
	int count = 0;
	char _case = 'X';

	convbase(X, base, &count, _case);
	return (count);
}
