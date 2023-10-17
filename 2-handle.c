#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * handle_p - handle p
 * @args: args
 * @count: integer
 * @buffer: char
 * @buffer_index: int
 *
 * Return: 0
 */
int handle_p(va_list args, char *buffer, int *buffer_index, int *count)
{
	void *ptr = va_arg(args, void *);

	if (ptr == NULL || buffer == NULL || buffer_index == NULL || count == NULL)
	{
		return (-1);
	}
	print_pointer(ptr, buffer, buffer_index, count);
	return (0);
}
