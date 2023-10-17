#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * print_hex_lower - print hex lower
 * @num: unsigned int
 * @buffer: char
 * @buffer_index: int
 * @count: int
 */
void print_hex_lower(
		unsigned int num, char *buffer, int *buffer_index, int *count)
{
	char temp, *num_str = malloc(12);
	int i, j, digit;

	if (num_str == NULL || buffer == NULL ||
			buffer_index == NULL || count == NULL)
	{
		exit(EXIT_FAILURE);
	}

	i = 0;
	while (num > 0)
	{
		digit = num % 16;
		if (digit < 10)
			num_str[i++] = digit + '0';
		else
			num_str[i++] = digit - 10 + 'a';
		num /= 16;
	}
	if (i == 0)
	{
		num_str[i++] = '0';
	}
	num_str[i] = '\0';


	for (j = 0; j < i / 2; j++)
	{
		temp = num_str[j];
		num_str[j] = num_str[i - j - 1];
		num_str[i - j - 1] = temp;
	}

	print_string(num_str, buffer, buffer_index, count);

	free(num_str);
}

/**
 * print_hex_upper - print hex upper
 * @num: unsigned int
 * @buffer: char
 * @buffer_index: int
 * @count: int
 */
void print_hex_upper(
		unsigned int num, char *buffer, int *buffer_index, int *count)
{
	char temp, *num_str = malloc(12);
	int i, j, digit;

	if (num_str == NULL || buffer == NULL ||
			buffer_index == NULL || count == NULL)
	{
		exit(EXIT_FAILURE);
	}

	i = 0;
	while (num > 0)
	{
		digit = num % 16;
		if (digit < 10)
			num_str[i++] = digit + '0';
		else
			num_str[i++] = digit - 10 + 'A';
		num /= 16;
	}
	if (i == 0)
	{
		num_str[i++] = '0';
	}
	num_str[i] = '\0';


	for (j = 0; j < i / 2; j++)
	{
		temp = num_str[j];
		num_str[j] = num_str[i - j - 1];
		num_str[i - j - 1] = temp;
	}

	print_string(num_str, buffer, buffer_index, count);

	free(num_str);
}
