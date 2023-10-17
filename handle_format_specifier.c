#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * handle_format_specifier - handle format specifier
 * @format: const char
 * @args: args
 * @count: integer
 * @buffer: char
 * @buffer_index: int
 *
 * Return: 0
 */
int handle_format_specifier(
		const char *format, va_list args,
		char *buffer, int *buffer_index, int *count)
{
	switch (*format)
	{
		case 'c':
			return (handle_character(args, buffer, buffer_index, count));
		case 's':
			return (handle_string(args, buffer, buffer_index, count));
		case '%':
			return (handle_percent(buffer, buffer_index, count));
		case 'd':
		case 'i':
			return (handle_integer(args, buffer, buffer_index, count));
		case 'b':
			return (handle_binary(args, buffer, buffer_index, count));
		case 'u':
			return (handle_unsigned_int(args, buffer, buffer_index, count));
		case 'o':
			return (handle_octal(args, buffer, buffer_index, count));
		case 'x':
			return (handle_hex_lower(args, buffer, buffer_index, count));
		case 'X':
			return (handle_hex_upper(args, buffer, buffer_index, count));
		case 'S':
			return (handle_S(args, buffer, buffer_index, count));
		case 'p':
			return (handle_p(args, buffer, buffer_index, count));
		default:
			return (-1);
	}
	return (0);
}
