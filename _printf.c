#include "main.h"
/**
* _printf - printf function
* @format: const char pointer
* Return: b_len
*/
int _printf(const char *format, ...)
{
int (*pfunc)(va_list, fmt_flags_t *);
const char *p;
va_list arguments;
fmt_flags_t flags = {0, 0, 0};

int _reg = 0;

va_start(arguments, format);
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (p = format; *p; p++)
{
if (*p == '%')
{
p++;
if (*p == '%')
{
_reg += _putchar('%');
continue;
}
while (get_flag(*p, &flags))
p++;
if (*p == '%')
{
_reg += _putchar('%');
continue;
}
while (get_flag(*p, &flags))
p++;
pfunc = get_print(*p);
_reg += (pfunc)
? pfunc(arguments, &flags)
: _printf("%%%c", *p);
}
else
{
_reg += _putchar(*p);
}
}
_putchar(-1);
va_end(arguments);
return (_reg);
}
