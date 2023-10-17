#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * handle_unsigned_int - handle unsigned
 * @args: args
 * @buffer: char
 * @buffer_index: int
 * @count: count
 *
 * Return: 0
 */
int handle_unsigned_int(
		va_list args, char *buffer, int *buffer_index, int *count)
{
	unsigned int num = va_arg(args, unsigned int);

	if (buffer == NULL || buffer_index == NULL || count == NULL)
	{
		return (-1);
	}

	print_unsigned_int(num);
	count++;

	return (0);
}

/**
 * handle_octal - handle octal
 * @args: args
 * @buffer: char
 * @buffer_index: int
 * @count: count
 *
 * Return: 0
 */
int handle_octal(va_list args, char *buffer, int *buffer_index, int *count)
{
	unsigned int num = va_arg(args, unsigned int);

	if (buffer == NULL || buffer_index == NULL || count == NULL)
	{
		return (-1);
	}
	print_octal(num, buffer, buffer_index, count);

	return (0);
}

/**
 * handle_hex_lower - handle hex lower
 * @args: args
 * @buffer: char
 * @buffer_index: int
 * @count: count
 *
 * Return: 0
 */
int handle_hex_lower(va_list args, char *buffer, int *buffer_index, int *count)
{
	unsigned int num = va_arg(args, unsigned int);

	if (buffer == NULL || buffer_index == NULL || count == NULL)
	{
		return (-1);
	}
	print_hex_lower(num, buffer, buffer_index, count);

	return (0);
}

/**
 * handle_hex_upper - handle hex upper
 * @args: args
 * @count: count
 * @buffer: char
 * @buffer_index: int
 *
 * Return: 0
 */
int handle_hex_upper(va_list args, char *buffer, int *buffer_index, int *count)
{
	unsigned int num = va_arg(args, unsigned int);

	if (buffer == NULL || buffer_index == NULL || count == NULL)
	{
		return (-1);
	}
	print_hex_upper(num, buffer, buffer_index, count);

	return (0);
}

/**
 * handle_S - handle S
 * @args: args
 * @count: count
 * @buffer: char
 * @buffer_index: int
 *
 * Return: 0
 */
int handle_S(va_list args, char *buffer, int *buffer_index, int *count)
{
	const char *s = va_arg(args, const char *);

	if (s == NULL || buffer == NULL || buffer_index == NULL || count == NULL)
	{
		return (-1);
	}

	print_escaped_string(s, buffer, buffer_index, count);
	return (0);
}
