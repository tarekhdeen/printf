#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * _printf - printf
 * @format: const char
 *
 * Return: count
 */
int _printf(const char *format, ...)
{
	int count = 0;
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
			if (handle_format_specifier(format, args, &count) == -1)
			{
				return (-1);
			}
		}
		else
		{
			print_char(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}
