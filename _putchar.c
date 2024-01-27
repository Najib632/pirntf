#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes character to stdout
 * @c: character to print
 *
 * Return: Always 1 (SUCCESS), -1 (FAILURE)
 **/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
