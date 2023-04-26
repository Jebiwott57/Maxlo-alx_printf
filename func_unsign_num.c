  #include "main.h"

/**
 * print_unsigned - a function that prints an unsigned number
 * @types: List of arguments
 * @buffer: The array to print unsigned nums
 * @flags:  Determines active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of unsigned nums printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int s = BS - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[s--] = '0';

	buffer[BS - 1] = '\0';

	while (num > 0)
	{
		buffer[s--] = (num % 10) + '0';
		num /= 10;
	}

	s++;

	return (write_unsigned_num(0, s, buffer, flags, width, precision, size));
}
