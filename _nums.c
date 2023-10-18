#include "main.h"

/**
 * convert - converter function, a clone of itoa
 *
 * @nu: number
 * @b: base
 * @fl: argument flags
 * @params: paramater struct
 *
 * Return: string
*/
char *convert(long int nu, int b, int fl, params_t *params)
{
	static char *arr;
	static char buff[50];
	char sign = 0;
	char *p;
	unsigned long n = nu;
	(void)params;

	if (!(fl & CONVERT_UNSIGNED) && nu < 0)
	{
		n = -nu;
		sign = '-';
	}
	arr = fl & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buff[49];
	*p = '\0';

	do {
		*--p = arr[n % b];
		n /= b;
	} while (n != 0);

	if (sign)
		*--p = sign;
	return (p);
}

/**
 * print_unsigned - prints unsigned integer numbers
 *
 * @p: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
*/
int print_unsigned(va_list p, params_t *params)
{
	unsigned long lo;

	if (params->l_modifier)
		lo = (unsigned long)va_arg(p, unsigned long);
	else if (params->h_modifier)
		lo = (unsigned short int)va_arg(p, unsigned int);
	else
		lo = (unsigned int)va_arg(p, unsigned int);
	params->unsign = 1;
	return (print_number(convert(1, 10, COMVERT_UNSIGNED, params), params));
}

/**
 * print_address - prints address
 *
 * @p: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
*/
int print_address(va_list p, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *s;

	if (!n)
		return (_puts("(nil)"));

	s = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--s = 'x';
	*--s = '0';
	return (print_number(s, params));
}
