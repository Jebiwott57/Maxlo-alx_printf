#include "main.h"

/**
 * print_hexa - a function that prints a hexadecimal number in lower or upper
 * @types: List of arguments
 * @map_to: Array of values that derive the number to
 * @buffer: The array to print a hexa num in lower or upper
 * @flags:  Determines active flags
 * @flag_ch: Determines active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of hexa num in lower or upper printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
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
		buffer[s--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[s--] = flag_ch;
		buffer[s--] = '0';
	}

	s++;

	return (write_unsigned_num(0, s, buffer, flags, width, precision, size));
}
