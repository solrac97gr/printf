#include "ft_printf.h"

t_FormatFunc get_format_func(char specifier)
{
    if (specifier == 'c')
        return format_char;
    else if (specifier == 's')
        return format_string;
    else if (specifier == 'p')
        return format_pointer;
    else if (specifier == 'd' || specifier == 'i')
        return format_integer;
    else if (specifier == 'u')
        return format_unsigned;
    else if (specifier == 'x')
        return format_hex_lower;
    else if (specifier == 'X')
        return format_hex_upper;
    else if (specifier == '%')
        return format_percent;
    else
        return NULL;
}

static t_FormatFunc format_funcs[128] = {0};

static void init_format_funcs(void)
{
    format_funcs['c'] = format_char;
    format_funcs['s'] = format_string;
    format_funcs['p'] = format_pointer;
    format_funcs['d'] = format_integer;
    format_funcs['i'] = format_integer;
    format_funcs['u'] = format_unsigned;
    format_funcs['x'] = format_hex_lower;
    format_funcs['X'] = format_hex_upper;
    format_funcs['%'] = format_percent;
}

t_FormatFunc get_format_func_alt(char specifier)
{
    static int initialized = 0;

    if (!initialized)
    {
        init_format_funcs();
        initialized = 1;
    }
    return format_funcs[(unsigned char)specifier];
}
