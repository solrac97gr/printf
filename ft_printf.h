/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:22:56 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/17 21:06:01 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

typedef int		(*t_FormatFunc)(va_list *);

static void	put_char(const char *c)
{
	write(1, c, 1);
}

int				format_char(va_list *args);
int				format_string(va_list *args);
int				format_pointer(va_list *args);
int				format_integer(va_list *args);
int				format_unsigned(va_list *args);
int				format_hex_lower(va_list *args);
int				format_hex_upper(va_list *args);
int				format_percent(va_list *args);
int				ft_printf(char const *format, ...);
