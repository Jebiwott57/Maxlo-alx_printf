#include "main.h"

/**
 * get_flags - a function that lists active flags
 * @format: input arguments printed by a pointer
 * @i: a pointer that points to the argument
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int s, math;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	math = *i + 1;
	for (; format[math] != '\0'; math++)
	{
		s = 0;
		while (FLAGS_CH[s] != '\0')
		{
			s++;
		}
			if (format[math] == FLAGS_CH[s])
			{
				flags |= FLAGS_ARR[s];
				break;
			}

		if (FLAGS_CH[s] == 0)
			break;
	}

	*i = math - 1;

	return (flags);
}
