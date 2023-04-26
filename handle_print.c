#include "main.h"
/**
<<<<<<< HEAD
 * handle_print - a function that prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: The array to print arguments
 * @flags: Determines active flags
=======
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: index.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
>>>>>>> max-practice
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: max;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int s, un_len = 0, max = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (s = 0; fmt_types[s].fmt != '\0'; s++)
		if (fmt[*ind] == fmt_types[s].fmt)
			return (fmt_types[s].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[s].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		un_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			un_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		un_len += write(1, &fmt[*ind], 1);
		return (un_len);
	}
	return (max);
}
