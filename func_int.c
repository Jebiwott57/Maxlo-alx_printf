#include "main.h"

/**
 * print_int - a function that prints int
 * @types: List of arguments
 * @buffer: The array to print int
 * @flags:  Determine active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of int printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int s = BS - 2;
	int is_negative = 0;
	long int t = va_arg(types, long int);
	unsigned long int num;

	t = convert_size_number(t, size);

	if (t == 0)
		buffer[s--] = '0';

	buffer[BS - 1] = '\0';
	num = (unsigned long int)t;

	if (t < 0)
	{
		num = (unsigned long int)((-1) * t);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[s--] = (num % 10) + '0';
		num /= 10;
	}

	s++;

	return (write_number(is_negative, s, buffer, flags, width, precision, size));
}
