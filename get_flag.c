#include "main.h"

/**
* get_flag - activates specific formatting flags
*when _printf encounters a flag specifier
* @s: the character holding the flag specifier
* @f: pointer to the struct fmt_flags where flags are set
*
* Return: 1 if a flag is successfully activated, 0 otherwise
*/
int get_flag(char s, fmt_flags *f)
{
int flag_activated = 0;

switch (s)
{
case '+':
f->plus = 1;
flag_activated = 1;
break;
case ' ':
f->space = 1;
flag_activated = 1;
break;
case '#':
f->hash = 1;
flag_activated = 1;
break;
}

return (flag_activated);
}
