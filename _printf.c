#include "main.h"

void print_buffer(char buffer[], int *bufindex);

/**
 * _printf - A function that prints a formatted output.
 * @format: A pointer pointing to the format of output.
 *
 * Return: bebo.
 */
int _printf(const char *format, ...)
{
	int s, printed = 0, bebo = 0;
	int flags, width, precision, size, bufindex = 0;
	va_list list;
	char buffer[BS];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (s = 0; format && format[s] != '\0'; s++)
	{
		if (format[s] != '%')
		{
			buffer[bufindex++] = format[s];
			if (bufindex == BS)
				print_buffer(buffer, &bufindex);

			bebo++;
		}
		else
		{
			print_buffer(buffer, &bufindex);
			flags = get_flags(format, &s);
			width = get_width(format, &s, list);
			precision = get_precision(format, &s, list);
			size = get_size(format, &s);
				++s;
			printed = handle_print(format, &s, list, buffer,
			flags, width, precision, size);

			if (printed == -1)
				return (-1);

			bebo = (bebo + printed);
		}
	}

	print_buffer(buffer, &bufindex);

	va_end(list);

	return (bebo);
}

/**
 * print_buffer - Prints buffer of output.
 * @buffer: Array of characters.
 * @bufindex: A pointer pointing to the next buffer to output.
 *
 * Return: void
 */
void print_buffer(char buffer[], int *bufindex)
{
	if (*bufindex > 0)
		write(1, &buffer[0], *bufindex);

	*bufindex = 0;
}
