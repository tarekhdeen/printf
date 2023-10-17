#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * print_string - print string
 * @s: const char
 * @buffer: char
 * @buffer_index: int
 * @count: int
 *
 * Return: 0
 */
int print_string(const char *s, char *buffer, int *buffer_index, int *count)
{
	int len;

	if (s == NULL || buffer == NULL || buffer_index == NULL)
	{
		return (-1);
	}

	len = strlen(s);

	if (*buffer_index + len >= BUFFER_SIZE)
	{
		write(1, buffer, *buffer_index);
		*buffer_index = 0;
	}
	strcpy(buffer + *buffer_index, s);
	*buffer_index += len;
	(*count) += len;

	return (0);
}
