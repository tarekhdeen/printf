#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * print_escaped_string - print string
 * @s: const char
 * @buffer: char
 * @buffer_index: int
 * @count: int
 *
 * Return: 0
 */
void print_escaped_string(
		const char *s, char *buffer, int *buffer_index, int *count)
{
	char hex[5];
	unsigned char c = (unsigned char)*s;

	if (s == NULL || buffer == NULL ||
			buffer_index == NULL || count == NULL)
	{
		return;
	}

	while (*s)
	{
		if (*s >= 32 && *s < 127)
		{
			print_char(*s, buffer, buffer_index, count);
		}
		else
		{
			hex[0] = '\\';
			hex[1] = 'x';
			hex[2] = "0123456789ABCDEF"[c / 16];
			hex[3] = "0123456789ABCDEF"[c % 16];
			hex[4] = '\0';
			print_string(hex, buffer, buffer_index, count);
		}
		s++;
	}
}
