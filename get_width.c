#include "main.h"

/**
 * get_width - a function that prints the width
 * @format: a pointer pointing to the argument to print
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int math;
	int width;

	math = *i + 1;
	for (; format[math] != '\0'; math++)

	{
		width = 0;
		if (is_digit(format[math]))
		{
			width = (width * 10);
			width = (width + format[math] - '0');
		}
		else if (format[math] == '*')
		{
			math++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = math - 1;

	return (width);
}
