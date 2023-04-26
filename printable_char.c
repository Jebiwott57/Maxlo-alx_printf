#include "main.h"

/**
 * is_printable - Function that scans for a printable character.
 * @c: Character to be scan.
 *
 * Return: 1 if character is printable or 0 otherwise.
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
