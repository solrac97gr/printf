/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:22:39 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/17 20:13:11 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Initialize the format function table (call this before using ft_printf)
static void	init_format_funcs(void)
{
	static int	initialized = 0;

	if (!initialized)
	{
		format_funcs['c'] = format_char;
		initialized = 1;
	}
}

/**
 * @brief Function to print formatted output.
 *
 * @param format The format string.
 * @param ... The values to format and print.
 */
int	ft_printf(char const *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;

	init_format_funcs();

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] && format_funcs[(unsigned char)format[i]])
			{
				count += format_funcs[(unsigned char)format[i]](&args);
			}
			else if (format[i])
			{
				put_char(&format[i]);
				count++;
			}
		}
		else
		{
			put_char(&format[i]);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}