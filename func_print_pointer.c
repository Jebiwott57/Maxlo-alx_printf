#include "main.h"

/*------------------- PRINT POINTER ------------------*/
/*
 * print_pointer- a function taht prints pointer variables
 * @types: List of arguments
 * @buffer: The array to print a pointer
 * @flags:  Determines active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: value of pointer variable printed.
 */
int print_pointer(va_list types, char buffer[],
int flags, int __attribute__((__unused__)) width,
	int precision, int __attribute__((__unused__)) size)
{
	char extra_c = 0, a = ' ';
	int s = BS - 2, length = 2, star = 1;
	unsigned long d_addrs;
	char cp_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	if (d_addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BS - 1] = '\0';
	UNUSED(precision);
	d_addrs = (unsigned long)d_addrs;

	while (d_addrs > 0)
	{
		buffer[s--] = cp_to[d_addrs % 16];
		d_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		a = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
	extra_c = ' ', length++;

	 s++;

	return (write_pointer(buffer, s, length,
		width, flags, a, extra_c, star));
}
