#include "main.h"

/**
 * convert_size_unsgnd - prints a number in a the specified size
 * @num: Number to be printed
 * @size: Number indicating the type to be printed
 *
 * Return: printed value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
