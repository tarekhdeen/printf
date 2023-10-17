#include <unistd.h>
#include <stdarg.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * print_char - writes the character c to stdout
 * @c: The character to print
 * @buffer: char
 * @buffer_index: int
 * @count: int
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_char(char c, char *buffer, int *buffer_index, int *count)
{
	if (buffer == NULL || buffer_index == NULL || count == NULL)
	{
		return (-1);
	}

	if (*buffer_index == BUFFER_SIZE - 1)
	{
		write(1, buffer, BUFFER_SIZE);
		*buffer_index = 0;
	}
	buffer[(*buffer_index)++] = c;
	(*count)++;

	return (1);
}
