#include "main.h"
/**
* convert - converts number and base into string
* @num: input number
* @base: input base
* @lowercase: flag if hexa values need to be lowercase
* Return: result string
*/
char *convert(unsigned long int num, int base, int lowercase)
{
static char *digits;
static char buffer[50];
char *result;

digits = (lowercase) ? "0123456789abcdef" : "0123456789ABCDEF";

result = &buffer[49];
*result = '\0';

while (num != 0)
{
*--result = digits[num % base];
num /= base;
}
return (result);
}
