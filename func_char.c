#include "main.h"

/**
 * print_char - a function that prints a char
 * @types: List a of arguments
 * @buffer: The  array to print a character
 * @flags:  Determine active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
