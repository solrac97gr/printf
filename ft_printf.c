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

int	ft_printf(char const *format, ...)
{
	va_list			args;
	int				i;
	int				count;
	t_FormatFunc	*format_funcs;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1]
			&& get_format_func((unsigned char)format[i + 1]))
		{
			count += get_format_func((unsigned char)format[++i])(&args);
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
