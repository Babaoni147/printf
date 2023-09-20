#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include <stdarg.h>

/**
* struct fmt_flags - struct containing flags to "turn on"
* when a flag specifier is passed to _printf()
* @plus: flag for the '+' character
* @space: flag for the ' ' character
* @hash: flag for the '#' character
*/
typedef struct fmt_flags
{
int plus;
int space;
int hash;
} fmt_flags_t;

/**
* struct handle_print - struct to choose the right function depending
* on the format specifier passed to _printf()
* @c: format specifier
* @f: pointer to the correct printing function
*/
typedef struct handle_print
{
char c;
int (*f)(va_list ap, fmt_flags_t *f);
} hp;

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
char *convert(unsigned long int num, int base, int lowercase);
int set_flags(char s, fmt_flags_t *f);
int (*get_print(char s))(va_list, fmt_flags_t *);
int print_hex_address(va_list l, fmt_flags_t *f);
int print_string(va_list l, fmt_flags_t *f);
int print_char(va_list l, fmt_flags_t *f);
int print_hex_lowercase(va_list l, fmt_flags_t *f);
int print_hex_uppercase(va_list l, fmt_flags_t *f);
int print_binary(va_list l, fmt_flags_t *f);
int print_octal(va_list l, fmt_flags_t *f);
int print_integer(va_list l, fmt_flags_t *f);
int print_unsigned_integer(va_list l, fmt_flags_t *f);
int count_digits(int i);
int print_non_printable(va_list l, fmt_flags_t *f);
int print_reverse(va_list l, fmt_flags_t *f);
int print_rot13(va_list l, fmt_flags_t *f);
int print_percent_symbol(va_list l, fmt_flags_t *f);
#endif
