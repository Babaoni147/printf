#include "main.h"

/**
* print_non_printable - prints non-printable characters as
* \x followed by ASCII code
* @l: va_list arguments from _printf
* @f: pointer to the struct fmt_flags that determines if a flag
* is passed to _printf
* Return: number of characters printed
*/
int print_non_printable(va_list l, fmt_flags_t *f)
{
int i, count = 0;
char *res;
char *s = va_arg(l, char *);

(void)f;
if (!s)
return (_puts("(null)"));

for (i = 0; s[i]; i++)
{
if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
{
_puts("\\x");
count += 2;
res = convert(s[i], 16, 0);
if (!res[1])
count += _putchar('0');
count += _puts(res);
}
else
count += _putchar(s[i]);
}
return (count);
}
/**
* print_reverse - prints a string in reverse
* @l: va_list arguments from _printf
* @f: pointer to the struct fmt_flags that determines if a
* flag is passed to _printf
* Return: length of the printed string
*/
int print_reverse(va_list l, fmt_flags_t *f)
{
int i = 0, j;
char *s = va_arg(l, char *);

(void)f;
if (!s)
s = "(null)";

while (s[i])
i++;

for (j = i - 1; j >= 0; j--)
_putchar(s[j]);

return (i);
}
/**
* print_rot13 - prints a string using ROT13 encoding
* @l: va_list arguments from _printf
* @f: pointer to the struct fmt_flags that determines if a
* flag is passed to _printf
* Return: length of the printed string
*/
int print_rot13(va_list l, fmt_flags_t *f)
{
int i, j;
char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
char *s = va_arg(l, char *);

(void)f;
for (j = 0; s[j]; j++)
{
if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
_putchar(s[j]);
else
{
for (i = 0; i <= 52; i++)
{
if (s[j] == rot13[i])
_putchar(ROT13[i]);
}
}
}

return (j);
}
/**
* print_percent_symbol - prints a percent symbol
* @l: va_list arguments from _printf
* @f: pointer to the struct fmt_flags in which we turn the flags on
* Return: number of characters printed
*/
int print_percent_symbol(va_list l, fmt_flags_t *f)
{
(void)l;
(void)f;
return (_putchar('%'));
}