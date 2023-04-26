#include "main.h"

/**
 * print_char - A function that printing chararacter.
 * @types: Arguments to print.
 * @buffer: The  array to print a character.
 * @flags:  Determine active flags.
 * @width: Width of output.
 * @precision: Precision specification for output.
 * @size: Size specifier for output.
 * Return: handle_write_char
 */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char);
}
