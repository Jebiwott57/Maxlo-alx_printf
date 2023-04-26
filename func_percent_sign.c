#include "main.h"

/**
 * print_percent - a function that prints a percent sign
 * @types: List of arguments
 * @buffer: The array to print percent sign
 * @flags:  Determine active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of percent sign printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
