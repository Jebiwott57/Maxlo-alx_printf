#include "main.h"

/**
 * print_rot13string - a function print a string in rot13.
 * @types: List of arguments
 * @buffer: The array to print a string in rot13
 * @flags:  Determines active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: strings in rot13
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char y;
	char *str;
	unsigned int s, h;
	int cash = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (s = 0; str[s]; s++)
	{
		for (h = 0; in[h]; h++)
		{
			if (in[h] == str[s])
			{
				y = out[h];
				write(1, &y, 1);
				cash++;
				break;
			}
		}
		if (!in[h])
		{
			y = str[s];
			write(1, &y, 1);
			cash++;
		}
	}
	return (cash);
}
