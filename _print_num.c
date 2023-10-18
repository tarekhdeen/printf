#include "main.h"

/**
 * is_digit - checks if character is digit
 *
 * @ch: the character to check
 *
 * Return: 1 if digit, 0 otherwise
*/
int _isdigit(int ch)
{
	return (ch >= '0' && ch <= '9');
}

/**
 * _strlen - returns the length of a string
 *
 * @s: the string whose length to check
 *
 * Return: integer length of string
*/
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints a number with options
 *
 * @s: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
*/
int print_number(char *s, params_t *params)
{
	unsigned int i = _strlen(s);
	int negat = (!params->unsign && *s == '-');

	if (!params->percision && *s == '0' && !s[1])
		s = "";
	if (negat)
	{
		s++;
		i--;
	}
	if (params->percision != UINT_MAX)
		while (i++ < params->percision)
			*--s = '0';
	if (negat)
		*--s = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(s, params));
	else
		return (print_number_left_shift(s, params));
}

/**
 * print_number_right_shift - print a number with options
 *
 * @s: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
*/
int print_number_right_shift(char *s, params_t *params)
{
	unsigned int n = 0, negat, negat2, i = _strlen(str);
	char padding_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		padding_char = '0';
	negat = negat2 = (!params->unsign && *s == '-');
	if (negat && i < params->width && padding_char == '0' && !params->minus_flag)
		s++;
	else
		negat = 0;
	if ((params->plus_flag && !negat2) ||
			(!params->plus_flag && params->space_flag && !negat2))
		i++;
	if (negat && padding_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !negat2 && padding_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !negat2 &&
			!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(padding_char);
	if (negat && padding_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !negat2 && padding_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !negat2 &&
			!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(s);
	return (n);
}

/**
 * print_number_left_shift - print a number with options
 * @s: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
*/
int print_number_left_shift(char *s, params_t *params)
{
	unsigned int n = 0, negat, negat2, i = _strlen(s);
	char padding_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		padding_char = '0';
	negat = negat2 = (!params->unsign && *s == '-');
	if (negat && i < params->width && padding_char == '0' && !params->minus_flag)
		s++;
	else
		negat = 0;

	if (params->plus_flag && !negat2 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->space_flag && !negat2 && !params->unsign)
		n += _putchar(' '), i++;
	n += _puts(s);
	while (i++ < params->width)
		n += _putchar(padding_char);
	return (n);
}
