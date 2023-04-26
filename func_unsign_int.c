#include "main.h"

/**
 * print_binary - a function that prints an unsigned number
 * @types: List of arguments
 * @buffer: The array to print unsigned ints
 * @flags:  Determines active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of unsigned ints printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int t, u, s, sum;
	unsigned int a[32];
	int cash;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	t = va_arg(types, unsigned int);
	u = 2147483648;
	a[0] = t / u;
	s = 1;
	for (; s < 32; s++)
	{
		u /= 2;
		a[s] = (t / u) % 2;
	}
	for (s = 0, sum = 0, cash = 0; s < 32; s++)
	{
		sum += a[s];
		if (sum || s == 31)
		{
			char z = '0' + a[s];

			write(1, &z, 1);
			cash++;
		}
	}
	return (cash);
}
