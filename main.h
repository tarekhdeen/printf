#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
void print_char(char c);
void print_string(const char *s);
void handle_format_specifier(const char *format, va_list args, int *count);

#endif /* MAIN_H */
