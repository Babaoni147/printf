#include "main.h"

/**
* print_hex_address - prints the hexadecimal address of input
* @l: va_list arguments from _printf
* @f: pointer to the struct fmt_flags that determines
* if a flag is passed to _printf
* Return: number of characters printed
*/
int print_hex_address(va_list l, fmt_flags_t *f)
{
char *str;
unsigned long int p = va_arg(l, unsigned long int);

int count = 0;

(void)f;

if (!p)
return (_puts("(nil)"));
str = convert(p, 16, 1);
count += _puts("0x");
count += _puts(str);
return (count);
}
