#include <stdarg.h>
#include <limits.h>
#include "main.h"

/**
* print_single_digit - Prints a single digit of an integer.
* @digit: The digit to print.
*/
void print_single_digit(int digit);

/**
* count_digits - Counts the number of digits in an integer.
* @number: The integer to evaluate.
* Return: Number of digits.
*/
int count_digits(int number);

/**
* print_number - Recursively prints all digits of an integer.
* @number: The integer to print.
*/
void print_number(int number);

/**
* print_integer - Prints an integer along with formatting options.
* @args: List of arguments from _printf.
* @flags: Pointer to format flags (fmt_flags_t).
* Return: Number of printed characters.
*/
int print_integer(va_list args, fmt_flags_t *flags)
{
int number = va_arg(args, int);
int result = count_digits(number);

if (flags->plus == 1 && number >= 0)
result += _putchar('+');
else if (flags->space == 1 && flags->plus == 0 && number >= 0)
result += _putchar(' ');
if (number < 0)
{
result++;
_putchar('-');
number = -number;
}

print_number(number);
return (result);
}

/**
* print_unsigned_integer - Prints an unsigned integer.
* @args: List of arguments from _printf.
* @flags: Pointer to format flags (fmt_flags_t).
* Return: Number of printed characters.
*/
int print_unsigned_integer(va_list args, fmt_flags_t *flags)
{
unsigned int u = va_arg(args, unsigned int);
char *str = convert(u, 10, 0);

(void)flags;

return (_puts(str));
}

/**
* print_single_digit - Prints a single digit of an integer.
* @digit: The digit to print.
*/
void print_single_digit(int digit)
{
_putchar(digit + '0');
}
/**
* count_digits - Counts the number of digits in an integer.
* @number: The integer to evaluate.
* Return: Number of digits.
*/
int count_digits(int number)
{
unsigned int positive_number = (number < 0) ? -number : number;
int digit_count = 0;

while (positive_number != 0)
{
positive_number /= 10;
digit_count++;
}

return (digit_count);
}

/**
* print_number - Recursively prints all digits of an integer.
* @number: The integer to print.
*/
void print_number(int number)
{
unsigned int positive_number;

if (number < 0)
{
_putchar('-');
positive_number = -number;
}
else
{
positive_number = number;
}

if (positive_number / 10)
print_number(positive_number / 10);

print_single_digit(positive_number % 10);
}
