#include "main.h"

/**
 * is_digit - checks if a char is a digit
 * @c: Char to be checked
 *
 * Return: 1 if c is a digit or 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
