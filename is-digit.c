#include "main.h"

/**
 * is_digit - scan for a digit.
 * @c: Char to scan.
 *
 * Return: 1 if c is a digit or 0 otherwise.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
