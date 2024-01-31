#include "main.h"

/**
 * get_fmt - Handles format specifiers
 * @spec: specifier
 *
 * Return: number of characters printed
 **/
int (*get_fmt(char spec))(va_list, char *)
{
	format_t formats[] = {
		{"c", handle_c},
		{"s", handle_s},
		{"d", handle_d},
		{"i", handle_d},
		{"b", handle_b},
		{"u", handle_u},
		{"o", handle_o},
		{"x", handle_x},
		{"X", handle_X},
		{NULL, fmterr}
	};
	int i = 0, j;

	for (j = 0; formats[j].spec != NULL; j++)
		;
	while (formats[i].spec != NULL)
	{
		if (spec == formats[i].spec[0])
			return (formats[i].handle);
		i++;
	}
	return (formats[j].handle);
}
