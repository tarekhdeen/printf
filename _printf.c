#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * _printf - printf
 * @format: const char
 *
 * Return: count
 */
int _printf(const char *format, ...)
{
	char buffer[BUFFER_SIZE];
	int buffer_index = 0, count = 0, rs;
	va_list args;

	va_start(args, format);

	if (format == NULL)
	{
		return (-1);
	}

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			rs = handle_format_specifier(format, args, buffer, &buffer_index, &count);

			if (rs == -1)
			{
				va_end(args);
				return (-1);
			}
		}
		else
		{
			print_char(*format, buffer, &buffer_index, &count);
		}
		format++;
	}

	flush_buffer(buffer, &buffer_index);

	va_end(args);
	return (count);
}
