#include "main.h"

/**
 * get_size - A function that gets size to print output.
 * @format: Pointer pointing to the format of the string.
 * @i: List of arguments to print in output.
 *
 * Return: size.
 */
int get_size(const char *format, int *i)
{
	int math = *i + 1;
	int size = 0;

	if (format[math] == 'l')
		size = S_LONG;

	else if (format[math] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = (math - 1);

	else /* if size != 0 */
		*i = math;

	return (size);
}
