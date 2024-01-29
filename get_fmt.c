#include "main.h"

/**
 * get_fmt - Handles format specifiers
 * @spec: specifier
 *
 * Return: number of characters printed
 **/
int (*get_fmt(char spec))(va_list)
{
	format_t formats[] = {
		{"c", handle_c},
		{"s", handle_s},
		/*{"d", handle_d},*/
		{NULL, NULL}
	};
	int i = 0;

	while (formats[i].spec != NULL)
	{
		if (spec == formats[i].spec[0])
			return (formats[i].handle);
		i++;
	}

	return (0);
}
