#include "main.h"

/**
 * print_hexa_upper - a function that prints unsign num in upper hexadecimal
 * @types: List of arguments
 * @buffer: The array to prints unsigned nums in upper hexa notation
 * @flags:  Determines active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of unsigned nums in upper hexa notation printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
			flags, 'X', width, precision, size));
}
