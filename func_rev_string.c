#include "main.h"

/**
 * print_reverse - a function that prints reverse string.
 * @types: List of arguments
 * @buffer: The array to print string in reverse
 * @flags:  Determines active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of revers strings printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int s, cash = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (s = 0; str[s]; s++)
		;

	for (s = s - 1; s >= 0; s--)
	{
		char z = str[s];

		write(1, &z, 1);
		cash++;
	}
	return (cash);
}
