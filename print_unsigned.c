#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * print_unsigned_int - print unsigned int
 * @num: unsigned integer
 */
void print_unsigned_int(unsigned int num)
{
		int num_digits = 1;
		unsigned int temp = num;

		while (temp /= 10)
		{
			num_digits++;
		}
}
