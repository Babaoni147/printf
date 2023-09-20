#include "main.h"

/**
* print_hex_lowercase - prints an unsigned number in hexadecimal base
* lowercase
* @l: va_list arguments from _printf
* @f: pointer to the struct fmt_flags that determines if a flag is
* passed to _printf
* Return: the number of characters printed
*/
int print_hex_lowercase(va_list l, fmt_flags_t *f)
{
unsigned int num = va_arg(l, unsigned int);
char *str = convert(num, 16, 1);
int count = 0;

if (f->hash == 1 && str[0] != '0')
count += _puts("0x");
count += _puts(str);
return (count);
}

/**
* print_hex_uppercase - prints an unsigned number in hexadecimal base
* uppercase
* @l: va_list arguments from _printf
* @f: pointer to the struct fmt_flags that determines if a flag is
* passed to _printf
* Return: the number of characters printed
*/
int print_hex_uppercase(va_list l, fmt_flags_t *f)
{
unsigned int num = va_arg(l, unsigned int);
char *str = convert(num, 16, 0);
int count = 0;
if (f->hash == 1 && str[0] != '0')
count += _puts("0X");
count += _puts(str);
return (count);
}

/**
* print_binary - prints an unsigned number in binary base
* @l: va_list arguments from _printf
* @f: pointer to the struct fmt_flags that determines if a
* flag is passed to _printf
* Return: the number of characters printed
*/
int print_binary(va_list l, fmt_flags_t *f)
{
unsigned int num = va_arg(l, unsigned int);
char *str = convert(num, 2, 0);

(void)f;
return (_puts(str));
}

/**
* print_octal - prints an unsigned number in octal base
* @l: va_list arguments from _printf
* @f: pointer to the struct fmt_flags that determines if
* a flag is passed to _printf
* Return: the number of characters printed
*/
int print_octal(va_list l, fmt_flags_t *f)
{
unsigned int num = va_arg(l, unsigned int);
char *str = convert(num, 8, 0);
int count = 0;

if (f->hash == 1 && str[0] != '0')
count += _putchar('0');
count += _puts(str);
return (count);
}
