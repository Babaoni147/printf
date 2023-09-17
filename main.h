#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/* macros for unused variables */
#define UNUSED(x) (void)(x)

/* buffer size constant */
#define BUFF_SIZE 1024

/* constants for formatting flags */
/* Using bitwise OR */
#define F_MINUS (1 << 0)  /* 0b00001 */
#define F_PLUS  (1 << 1)  /* 0b00010 */
#define F_ZERO  (1 << 2)  /* 0b00100 */
#define F_HASH  (1 << 3)  /* 0b01000 */
#define F_SPACE (1 << 4)  /* 0b10000 */

/* Using powers of 2 for easy bit manipulation */
/* constants for data sizes */
#define S_LONG  (1 << 0)  /* 0b00001 */
#define S_SHORT (1 << 1)  /* 0b00010 */

/* Constants for data sizes */
#define S_LONG  (1 << 0)
#define S_SHORT (1 << 1)

/**
 * struct fmt_opt - Struct op
 *
 * @fmt_opt: The format.
 * @func_a: The function associated.
 */

struct fmt_opt
{
        char fmt_opt;
        int (*func_a)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt_opt fmt_t - Struct op
 *
 * @fmt_opt: The format.
 * @fmt_t: The function associated.
 */

typedef struct fmt_opt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt_opt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);


/****************** FUNCTIONS ******************/


/* Funtions to print chars and strings */

int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size);


/* Functions to print numbers */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);


/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* Function to print string in reverse */
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Function to print a string in rot 13 */
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size);


/****************** UTILS ******************/

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
