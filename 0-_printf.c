#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * print_char - print char
 * @c: char
 */
void print_char(char c)
{
	write(1, &c, 1);
}

/**
 * print_string - print string
 * @s: string
 */
void print_string(const char *s)
{
	int len = strlen(s);

	write(1, s, len);
}

/**
 * handle_format_specifier - handle format specefier
 * @format: format
 * @args: va_list
 * @count: intger
 */
void handle_format_specifier(const char *format, va_list args, int *count)
{
	char c;
	const char *s;

	switch (*format)
	{
		case 'c':
			{
				c = va_arg(args, int);
				print_char(c);
				(*count)++;
				break;
			}
		case 's':
			{
				s = va_arg(args, const char *);
				print_string(s);
				(*count) += strlen(s);
				break;
			}
		case '%':
			print_char('%');
			(*count)++;
			break;
		default:

			break;
	}
}

/**
 * _printf - printf
 * @format: char
 *
 * Return: count
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			handle_format_specifier(format, args, &count);
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
