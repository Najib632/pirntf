#include "main.h"

/**
 * handle_S - Non printable characters are printed this way: \xHEXVAL
 * @args: pointer to va_list object
 * @buff: pointer to buffer
 * @bufpos: pointer to buffer position
 *
 * Return: 1 (SUCCESS), -1 (FAIL)
 **/
int handle_S(va_list *args, char *buff, int *bufpos)
{
	char *str = va_arg(*args, char *);
	unsigned char c;
	unsigned int i, base = 16;

	if (str == NULL)
	{
		buffwrite(buff, "(null)", bufpos);
		return (-1);
	}
	for (i = 0; str[i]; i++, *bufpos = *bufpos + 1)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			c = (unsigned char) str[i];
			if (c > 0 && c < 16)
				buffwrite(buff, "\\x0", bufpos);
			else
				buffwrite(buff, "\\x", bufpos);
			convbase(c, base, 'X', buff, bufpos);
		}
		else
			buff[*bufpos] = str[i];
	}
	return (1);
}
