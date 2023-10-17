#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * print_pointer - print pointer
 * @ptr: pointer
 * @buffer: char
 * @buffer_index: int
 * @count: int
 *
 * Return: 0
 */
void print_pointer(void *ptr, char *buffer, int *buffer_index, int *count)
{
	char hex[17];
	unsigned long uintptr = (unsigned long)ptr;
	int i;

	if (ptr == NULL || buffer == NULL ||
			buffer_index == NULL || count == NULL)
	{
		return;
	}

	hex[0] = '0';
	hex[1] = 'x';
	for (i = 15; i >= 2; i--)
	{
		hex[i] = "0123456789ABCDEF"[uintptr % 16];
		uintptr /= 16;
	}
	hex[16] = '\0';

	i = 0;
	while (hex[i])
	{
		buffer[*buffer_index] = hex[i];
		(*buffer_index)++;
		i++;
	}

	*count += 16;
}
