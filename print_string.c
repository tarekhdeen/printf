#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * print_string - print string
 * @s: const char
 *
 * Return: 0
 */
int print_string(const char *s)
{
	if (s == NULL)
	{
		return (-1);
	}
	else
	{
		int len = strlen(s);

		write(1, s, len);
	}
	return (0);
}
