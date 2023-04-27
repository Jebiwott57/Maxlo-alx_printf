#include "main.h"

/**
 * write_num - Write a number using a buffer.
 * @index: Index at which the number starts on the buffer.
 * @buffer: Buffer.
 * @flags: Flags.
 * @width: width.
 * @precision: Precision specifier.
 * @length: Number length.
 * @a: Padding character.
 * @extra: Extra character.
 *
 * Return: write(1, &buffer[index], length).
 */
int write_num(int index, char buffer[], int flags, int width,
	int precision, int length, char a, char extra)
{
	int i, a_start = 1;

	if (precision == 0 && index == (BS - 2) && buffer[index] == '0' && width == 0)
		return (0);
	if (precision == 0 && index == (BS - 2) && buffer[index] == '0')
		buffer[index] = a = ' ';
	if (precision > 0 && precision < length)
		a = ' ';
	while (precision > length)
		buffer[--index] = '0', length++;
	if (extra != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = a;
		buffer[i] = '\0';
		if (flags & F_MINUS && a == ' ')
		{
			if (extra)
				buffer[--index] = extra;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], (i - 1)));
		}
		else if (!(flags & F_MINUS) && a == ' ')
		{
			if (extra)
				buffer[--index] = extra;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && a == '0')
		{
			if (extra)
				buffer[--a_start] = extra;
			return (write(1, &buffer[a_start], (i - a_start)) +
					write(1, &buffer[index], length - (1 - a_start)));
		}
	}
	if (extra)
		buffer[--index] = extra;
	return (write(1, &buffer[index], length));
}

/**
 * write_unsigned_num - A function that writes an unsigned number.
 * @is_negative: Number is negative.
 * @index: Index number the buffer starts.
 * @buffer: Array of characters.
 * @flags: Flags specifiers for output.
 * @width: Width specifier for output.
 * @precision: Precision specifier for output.
 * @size: Size specifier for output.
 *
 * Return: characters (right justified).
 */
int write_unsigned_num(int __attribute__((__unused__)) is_negative,
	int index, char buffer[], int flags, int width,
	int precision, int __attribute__((__unused__)) size)
{
	int length = BS - index - 1, i = 0;
	char padd = ' ';

	if (precision == 0 && index == (BS - 2) && buffer[index] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[index], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[index], length));
		}
	}

	return (write(1, &buffer[index], length));
}
