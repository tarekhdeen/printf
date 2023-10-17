#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * flush_buffer - flush buffer
 * @buffer: char
 * @buffer_index: int
 */
void flush_buffer(char *buffer, int *buffer_index)
{
	int written;

	if (buffer == NULL || buffer_index == NULL)
	{
		return;
	}

	if (*buffer_index > 0)
	{
		written = write(1, buffer, *buffer_index);
		if (written < 0)
		{
			exit(EXIT_FAILURE);
		}
		*buffer_index = 0;
	}
}
