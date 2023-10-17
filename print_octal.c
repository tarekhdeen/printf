#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * print_octal - print octal
 * @num: unsigned integer
 * @buffer: char
 * @buffer_index: int
 * @count: int
 */
void print_octal(unsigned int num, char *buffer, int *buffer_index, int *count)
{
	char *num_str;
	int i, num_digits = 1;
	unsigned int temp = num;

	if (buffer == NULL || buffer_index == NULL || count == NULL)
	{
		return;
	}

	while (temp /= 8)
	{
		num_digits++;
	}

	num_str = malloc(num_digits + 1);

	if (num_str == NULL)
	{
		exit(EXIT_FAILURE);
	}

	i = 0;
	while (num > 0)
	{
		num_str[i++] = (num % 8) + '0';
		num /= 8;
	}
	num_str[i] = '\0';

	print_string(num_str, buffer, buffer_index, count);

	free(num_str);
}
