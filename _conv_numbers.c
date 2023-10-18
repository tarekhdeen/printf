#include "main.h.txt"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * 
 * @p: the argument pointer
 * @params: the parameters struct
 * 
 * Return: bytes printed
*/
int print_hex(va_list p, params_t *params)
{
	unsigned long lo;
	int c = 0;
	char *s;

	if (params->l_modifier)
		lo = (unsigned long)va_arg(p, unsigned long);
	else if (params->h_modifier)
		lo = (unsigned short int)va_arg(p, unsigned int);
	else
		lo = (unsigned int)va_arg(p, unsigned int);

	s = convert(lo, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--s = 'x';
		*--s = '0';
	}
	params->unsign = 1;
	return (c += print_number(s, params));
}
/**
 * print_HEX - prints unsigned hex numbers in uppercase
 *
 * @p: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
*/
int print_HEX(va_list p, params_t *params)
{
	unsigned long lo;
	int c = 0;
	char *s;

	if (params->l_modifier)
		lo = (unsigned long)va_arg(p, unsigned long);
	else if (params->h_modifier)
		lo = (unsigned short int)va_arg(p, unsigned int);
	else
		lo = (unsigned int)va_arg(p, unsigned int);

	s = convert(lo, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && lo)
	{
		*--s = 'X';
		*--s = '0';
	}
	params->unsign = 1;
	return (c += print_number(s, params));
}
/**
 * print_binary - prints unsigned binary number
 *
 * @p: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
*/
int print_binary(va_list ap, params_t *params)
{
	unsigned int n = va_arg(p, unsigned int);
	char *s = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && n)
		*--s = '0';
	params->unsign = 1;
	return (c += print_number(s, params));
}
/**
 * print_octal - prints unsigned octal numbers
 * @p: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
*/
int print_octal(va_list p, params_t *params)
{
	unsigned long lo;
	char *s;
	int c = 0;

	if (params->l_modifier)
		lo = (unsigned long)va_arg(p, unsigned long);
	else if (params->h_modifier)
		lo = (unsigned short int)va_arg(p, unsigned int);
	else
		lo = (unsigned int)va_arg(p, unsigned int);
	s = convert(lo, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && lo)
		*--s = '0';
	params->unsign = 1;
	return (c += print_number(s, params));
}
