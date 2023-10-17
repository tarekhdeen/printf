#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * print_binary - print binary
 * @num: unsigned integer
 * @buffer: char
 * @buffer_index: int
 * @count: int
 */
void print_binary(
		unsigned int num, char *buffer, int *buffer_index, int *count)
{
	char bin_str[33];
	int i;

	if (buffer == NULL || buffer_index == NULL || count == NULL)
	{
		return;
	}

	bin_str[32] = '\0';
	for (i = 31; i >= 0; i--)
	{
		bin_str[i] = (num & 1) ? '1' : '0';
		num >>= 1;
	}

	print_string(bin_str, buffer, buffer_index, count);
}
