/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:22:39 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/17 21:23:06 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Initialize the format function table (call this before using ft_printf)
static t_FormatFunc	*init_format_funcs(void)
{
	static t_FormatFunc	format_funcs[128] = {0};
	static int			initialized = 0;

	if (!initialized)
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
		initialized = 1;
	}
	return (format_funcs);
}

int	ft_printf(char const *format, ...)
{
	va_list			args;
	int				i;
	int				count;
	t_FormatFunc	*format_funcs;

	i = 0;
	count = 0;
	format_funcs = init_format_funcs();
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1]
			&& format_funcs[(unsigned char)format[i + 1]])
		{
			count += format_funcs[(unsigned char)format[++i]](&args);
		}
		else
		{
			ft_put_char(&format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
