#include "main.h"

/**
 * handle_p - Handles pointer conversion
 * @args: pointer to valist object
 * @buff: pointer to buffer
 * @bufpos: pointer to buffer position
 *
 * Return: 1 (SUCCESS), 0 (FAIL)
 */
int handle_p(va_list *args, char *buff, int *bufpos)
{
	unsigned char *addr = (unsigned char *)va_arg(*args, void *);

	if (addr == NULL)
	{
		buffwrite(buff, "NULL", bufpos);
		return (0);
	}
	buff[++*bufpos] = '0';
	buff[++*bufpos] = 'x';
	++*bufpos;
	convbase((unsigned long int)addr, 16, 'x', buff, bufpos);
	return (1);
}
