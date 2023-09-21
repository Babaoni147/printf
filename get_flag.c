#include "main.h"
/**
* get_flag - gets flags if _printf finds
* @s: character that holds the flag specifier
* @f: pointer to the struct fmt_flags in which we set the flags
*
* Return: 1 if a flag has been set, 0 otherwise
*/
int get_flag(char s, fmt_flags_t *f)
{
int flag_set = 0;

if (s == '+')
{
f->plus = 1;
flag_set = 1;
}
else if (s == ' ')
{
f->space = 1;
flag_set = 1;
}
else if (s == '#')
{
f->hash = 1;
flag_set = 1;
}

return (flag_set);
}
