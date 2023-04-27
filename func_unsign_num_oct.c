#include "main.h"

/**
 * print_octal - a function that prints an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: The array to print unsigned nums in octal notation
 * @flags:  Determines active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of unsigned nums in octal notation printed
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{

	int s = BS - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[s--] = '0';

	buffer[BS - 1] = '\0';

	while (num > 0)
	{
		buffer[s--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[s--] = '0';

	s++;

	return (write_unsigned_num(0, s, buffer, flags, width, precision, size));
}
