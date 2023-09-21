#include "main.h"
/**
* _printf - Custom printf function
* @format: Format string
* Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
int (*print_fun)(va_list, fmt_flags_t *);
const char *p;
va_list args;
fmt_flags_t flags = {0, 0, 0};
int chars_printed = 0;

va_start(args, format);
if (!format || (format[0] == '%' && !format[1]) ||
(format[0] == '%' && format[1] == ' ' && !format[2]))
return (-1);
for (p = format; *p; p++)
{
if (*p == '%')
{
p++;
if (*p == '%')
{
chars_printed += _putchar('%');
continue;
}
while (get_flag(*p, &flags))
p++;
if (*p == '%')
{
chars_printed += _putchar('%');
continue;
}
while (get_flag(*p, &flags))
p++;
print_fun = get_print(*p);
chars_printed += (print_fun) ? print_fun(args, &flags) :
_printf("%%%c", *p);
}
else
chars_printed += _putchar(*p);
}
_putchar(-1);
va_end(args);
return (chars_printed);
}
