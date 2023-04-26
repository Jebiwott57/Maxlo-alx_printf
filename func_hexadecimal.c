#include "main.h"

/**
 * print_hexadecimal - a function that prints unsign num in hexadecimal note
 * @types: List of arguments
 * @buffer: The array to print unsigned nums in hexa notation
 * @flags:  Determines active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of unsigned nums in hexa notation printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
			flags, 'x', width, precision, size));
}
