#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * handle_character - handle c
 * @args: args
 * @count: integer
 *
 * Return: 0
 */
int handle_character(va_list args, int *count)
{
	char c = va_arg(args, int);

	if (count == NULL)
	{
		return (-1);
	}

	print_char(c);
	(*count)++;
	return (0);
}

/**
 * handle_string - handle s
 * @args: args
 * @count: integer
 *
 * Return: 0
 */
int handle_string(va_list args, int *count)
{
	const char *s = va_arg(args, const char *);
	int result = print_string(s);

	if (result == -1 || count == NULL)
	{
		return (-1);
	}
	(*count) += strlen(s);
	return (0);
}

/**
 * handle_percent - handle %
 * @count: integer
 *
 * Return: 0
 */
int handle_percent(int *count)
{
	if (count == NULL)
	{
		return (-1);
	}

	print_char('%');
	(*count)++;
	return (0);
}

/**
 * handle_integer - handle integer
 * @args: args
 * @count: intger
 *
 * Return: 0
 */
int handle_integer(va_list args, int *count)
{
	char num_str[12];
	int num, result;

	num = va_arg(args, int);
	sprintf(num_str, "%d", num);
	result = print_string(num_str);

	if (result == -1 || count == NULL)
	{
		return (-1);
	}
	(*count) += strlen(num_str);
	return (0);
}

/**
 * handle_format_specifier - handle format specifier
 * @format: const char
 * @args: args
 * @count: integer
 *
 * Return: 0
 */
int handle_format_specifier(const char *format, va_list args, int *count)
{
	switch (*format)
	{
		case 'c':
			return (handle_character(args, count));
		case 's':
			return (handle_string(args, count));
		case '%':
			return (handle_percent(count));
		case 'd':
		case 'i':
			return (handle_integer(args, count));
		default:
			return (-1);
	}
	return (0);
}
