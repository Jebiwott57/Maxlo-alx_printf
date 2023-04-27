#include "main.h"

/**
 * add_hexadecimal - Add ascci in hexadecimal to buffer
 * @buffer: Array of chars.
 * @s: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int add_hexadecimal(char ascii_code, char buffer[], int s)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[s++] = '\\';
	buffer[s++] = 'x';

	buffer[s++] = map_to[ascii_code / 16];
	buffer[s] = map_to[ascii_code % 16];

	return (3);
}
