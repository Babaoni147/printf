#include "main.h"
#include <unistd.h>

/**
* _putchar - writes the character c to stdout
* @c: The character to print
* Return: On success 1. On error, -1 is returned.
*/
int _putchar(char c)
{
static char output_buffer[1024];
static int buffer_index;

if (buffer_index >= 1024 || c == -1)
{
write(1, output_buffer, buffer_index);
buffer_index = 0;
}
if (c != -1)
{
output_buffer[buffer_index] = c;
buffer_index++;
}
return (1);
}

/**
* _puts - prints a string to stdout
* @str: pointer to the string to print
* Return: number of characters written
*/
int _puts(char *str)
{
int i = 0;

while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
return (i);
}
