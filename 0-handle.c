#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * handle_character - handle c
 * @args: args
 * @count: integer
 * @buffer: char
 * @buffer_index: int
 *
 * Return: 0
 */
int handle_character(va_list args, char *buffer, int *buffer_index, int *count)
{
	char c = va_arg(args, int);

	if (count == NULL)
	{
		return (-1);
	}

	print_char(c, buffer, buffer_index, count);
	return (0);
}

/**
 * handle_string - handle s
 * @args: args
 * @count: integer
 * @buffer: char
 * @buffer_index: int
 *
 * Return: 0
 */
int handle_string(va_list args, char *buffer, int *buffer_index, int *count)
{
	const char *s = va_arg(args, const char *);
	int result = print_string(s, buffer, buffer_index, count);

	if (result == -1 || *buffer == -1 || *buffer_index == -1 || *count == -1)
	{
		return (-1);
	}
	return (0);
}

/**
 * handle_percent - handle %
 * @count: integer
 * @buffer: char
 * @buffer_index: int
 *
 * Return: 0
 */
int handle_percent(char *buffer, int *buffer_index, int *count)
{
	if (count == NULL)
	{
		return (-1);
	}
	print_char('%', buffer, buffer_index, count);
	(*count)++;
	return (0);
}

/**
 * handle_integer - handle integer
 * @args: args
 * @count: intger
 * @buffer: char
 * @buffer_index: int
 *
 * Return: 0
 */
int handle_integer(va_list args, char *buffer, int *buffer_index, int *count)
{
	char *num_str;
	int num = va_arg(args, int);
	int temp, result, i, digits = 0;

	while (temp != 0)
	{
		temp /= 10;
		digits++;
	}

	num_str = (char *)malloc(digits + 1);
	if (num_str == NULL)
	{
		exit(EXIT_FAILURE);
	}
	for (i = digits - 1; i >= 0; i--)
	{
		num_str[i] = '0' + num % 10;
		num /= 10;
	}
	num_str[digits] = '\0';

	result = print_string(num_str, buffer, buffer_index, count);

	if (result == -1 || buffer == NULL || *buffer_index == -1 || *count == -1)
	{
		return (-1);
	}

	(*count) += digits;

	free(num_str);

	return (0);
}

/**
 * handle_binary - handle binary
 * @args: args
 * @buffer: char
 * @buffer_index: int
 * @count: count
 *
 * Return: 0
 */
int handle_binary(va_list args, char *buffer, int *buffer_index, int *count)
{
	unsigned int num = va_arg(args, unsigned int);

	if (count == NULL)
	{
		return (-1);
	}
	print_binary(num, buffer, buffer_index, count);

	return (0);
}
