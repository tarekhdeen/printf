#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024

#include <stdarg.h>


int _printf(const char *format, ...);
int print_char(char c, char *buffer, int *buffer_index, int *count);
int print_string(const char *s, char *buffer, int *buffer_index, int *count);
void print_binary(
		unsigned int num, char *buffer, int *buffer_index, int *count);
void print_unsigned_int(unsigned int num);
void print_octal(
		unsigned int num, char *buffer, int *buffer_index, int *count);
void print_hex_lower(
		unsigned int num, char *buffer, int *buffer_index, int *count);
void print_hex_upper(
		unsigned int num, char *buffer, int *buffer_index, int *count);
void flush_buffer(char *buffer, int *buffer_index);
void print_escaped_string(
		const char *s, char *buffer, int *buffer_index, int *count);
void print_pointer(void *ptr, char *buffer, int *buffer_index, int *count);
int handle_character(
		va_list args, char *buffer, int *buffer_index, int *count);
int handle_string(va_list args, char *buffer, int *buffer_index, int *count);
int handle_percent(char *buffer, int *buffer_index, int *count);
int handle_integer(va_list args, char *buffer, int *buffer_index, int *count);
int handle_binary(va_list args, char *buffer, int *buffer_index, int *count);
int handle_unsigned_int(
		va_list args, char *buffer, int *buffer_index, int *count);
int handle_octal(va_list args, char *buffer, int *buffer_index, int *count);
int handle_hex_lower(
		va_list args, char *buffer, int *buffer_index, int *count);
int handle_hex_upper(
		va_list args, char *buffer, int *buffer_index, int *count);
int handle_S(va_list args, char *buffer, int *buffer_index, int *count);
int handle_p(va_list args, char *buffer, int *buffer_index, int *count);
int handle_format_specifier(
const char *format, va_list args, char *buffer, int *buffer_index, int *count);

#endif /* MAIN_H */
