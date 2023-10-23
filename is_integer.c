#include "monty.h"

/**
 * is_integer - Checks if the string represents is a valid integer or not.
 * @str: The string to be checked.
 *
 * Return: 1 if str is a valid integer, 0 otherwise.
 */

int is_integer(char *str)
{
	if (*str == '-' || *str == '+')
		str++;

	if (!str || *str == '\0')
		return (0);

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}
