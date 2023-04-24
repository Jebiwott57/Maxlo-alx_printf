#include "main.h"

/**
 * get_precision - a function that produces the precision for the output
 * @format: pointer to the format of the string
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int math = *i + 1;
	int precision = -1;

	if (format[math] != '.')
		return (precision);

	precision = 0;
	math = math + 1;
	for (; format[math] != '\0'; math++)
	{
		if (is_digit(format[math]))
		{
			precision = precision * 10;
			precision = precision + format[math] - '0';
		}
		else if (format[math] == '*')
		{
			math++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = math - 1;

	return (precision);
}
