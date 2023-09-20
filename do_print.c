#include "main.h"

/**
* get_print - selects the right printing function
* depending on the conversion specifier passed to _printf
* @s: character that holds the conversion specifier
*
* Return: a pointer to the matching printing function
*/
int (*get_print(char s))(va_list, fmt_flags_t *)
{
hp func_arr[] = {
{'i', print_integer},
{'s', print_string},
{'c', print_char},
{'d', print_integer},
{'u', print_unsigned_integer},
{'x', print_hex_lowercase},
{'X', print_hex_uppercase},
{'b', print_binary},
{'o', print_octal},
{'R', print_rot13},
{'r', print_reverse},
{'S', print_non_printable},
{'p', print_hex_address},
{'%', print_percent_symbol}
};

int i = 0;

int num_funcs = sizeof(func_arr) / sizeof(func_arr[0]);

for (; i < num_funcs; i++)
{
if (func_arr[i].c == s)
{
return (func_arr[i].f);
}
}

return (NULL);
}
