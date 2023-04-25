#include "main.h"

/**
 * print_non_printable - function printing ascii codes in hexa
 * @types: List of arguments
 * @buffer: The array to print ascii codes in hexa of non printable chars
 * @flags:  Determines active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of non printable chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int s = 0, quavo = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[s] != '\0')
{
	if (is_printable(str[s]))
		buffer[s + quavo] = str[s];
	else
		quavo += add_hexadecimal(str[s], buffer, s + quavo);
	s++;
}

	buffer[s + quavo] = '\0';

	return (write(1, buffer, s + quavo));
}
