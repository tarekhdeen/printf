#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(const char *s);
int handle_character(va_list args, int *count);
int handle_string(va_list args, int *count);
int handle_percent(int *count);
int handle_integer(va_list args, int *count);
int handle_format_specifier(const char *format, va_list args, int *count);

#endif /* MAIN_H */
