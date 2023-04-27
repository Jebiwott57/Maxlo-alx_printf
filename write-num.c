#include "main.h"

/**
<<<<<<< HEAD
 * write_num - Write a number using a bufffer.
=======
 * write_num - Write a number using a buffer.
>>>>>>> 130da53986018eb1187c5555c2b60d7da2a7385a
 * @index: Index at which the number starts on the buffer.
 * @buffer: Buffer.
 * @flags: Flags.
 * @width: width.
 * @precision: Precision specifier.
 * @length: Number length.
<<<<<<< HEAD
 * @padd: Pading character.
=======
 * @a: Padding character.
>>>>>>> 130da53986018eb1187c5555c2b60d7da2a7385a
 * @extra: Extra character.
 *
 * Return: write(1, &buffer[index], length).
 */
int write_num(int index, char buffer[], int flags, int width,
<<<<<<< HEAD
		int precision, int length, char padd, char extra)
{
	int i, padd_start = 1;
=======
	int precision, int length, char a, char extra)
{
	int i, a_start = 1;
>>>>>>> 130da53986018eb1187c5555c2b60d7da2a7385a

	if (precision == 0 && index == (BS - 2) && buffer[index] == '0' && width == 0)
		return (0);
	if (precision == 0 && index == (BS - 2) && buffer[index] == '0')
<<<<<<< HEAD
		buffer[index] = padd = ' ';
	if (precision > 0 && precision < length)
		padd = ' ';
=======
		buffer[index] = a = ' ';
	if (precision > 0 && precision < length)
		a = ' ';
>>>>>>> 130da53986018eb1187c5555c2b60d7da2a7385a
	while (precision > length)
		buffer[--index] = '0', length++;
	if (extra != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
<<<<<<< HEAD
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')/* right justified character */
=======
			buffer[i] = a;
		buffer[i] = '\0';
		if (flags & F_MINUS && a == ' ')
>>>>>>> 130da53986018eb1187c5555c2b60d7da2a7385a
		{
			if (extra)
				buffer[--index] = extra;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], (i - 1)));
		}
<<<<<<< HEAD
		else if (!(flags & F_MINUS) && padd == ' ')/* left justify character */
=======
		else if (!(flags & F_MINUS) && a == ' ')
>>>>>>> 130da53986018eb1187c5555c2b60d7da2a7385a
		{
			if (extra)
				buffer[--index] = extra;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], length));
		}
<<<<<<< HEAD
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra)
				buffer[--padd_start] = extra;
			return (write(1, &buffer[padd_start], (i - padd_start)) +
					write(1, &buffer[index], length - (1 - padd_start)));
=======
		else if (!(flags & F_MINUS) && a == '0')
		{
			if (extra)
				buffer[--a_start] = extra;
			return (write(1, &buffer[a_start], (i - a_start)) +
					write(1, &buffer[index], length - (1 - a_start)));
>>>>>>> 130da53986018eb1187c5555c2b60d7da2a7385a
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
<<<<<<< HEAD
		int index, char buffer[], int flags, int width,
		int precision, int __attribute__((__unused__)) size)
=======
	int index, char buffer[], int flags, int width,
	int precision, int __attribute__((__unused__)) size)
>>>>>>> 130da53986018eb1187c5555c2b60d7da2a7385a
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
