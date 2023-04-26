#include "main.h"
/**
 * handle_write_char - Prints a string
 * @c: Character specifier.
 * @buffer: Buffer array to print in output.
 * @flags:  Active flags.
 * @width: width to output.
 * @precision: precision specifier of output.
 * @size: Size for output.
 *
 * Return: characters in output.
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int __attribute__((__unused__)) precision,
	int size)
{ /* left justified character to print */
	int s = 0;
	char padd = ' ';

	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[s++] = c;
	buffer[s] = '\0';

	if (width > 1)
	{
		buffer[BS - 1] = '\0';
		for (s = 0; s < width - 1; s++)
			buffer[BS - s - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BS - s - 1], width - 1));
		else
			return (write(1, &buffer[BS - s - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char buffer[], int flags,
		int width, int precision, int __attribute__((__unused__)) size)
{
	int length = BS - ind - 1;
	char padd = ' ', extra_ch = 0;

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}
