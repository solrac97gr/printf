/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:22:39 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/19 18:22:56 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief ft_printf function that formats and prints the given string
 * according to the specified format.
 *
 * format is a string that can contain characters and format specifiers.
 * The format specifiers are preceded by a '%' character.
 *

 * @param format The format string containing the characters
 * and format specifiers.
 * @param ... The values to be formatted and printed.
 * @return The number of characters printed.
 */
int	ft_printf(char const *format, ...)
{
	va_list			args;
	int				i;
	int				count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1]
			&& get_format_func(format[i + 1]))
		{
			count += get_format_func(format[++i])(&args);
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
