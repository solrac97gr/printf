/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:22:56 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/17 20:14:05 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>


typedef int			(*FormatFunc)(va_list *);

// Direct access table for format specifiers
// ASCII has 128 values, so we allocate that much space
// Each entry contains a function pointer (or NULL if not valid)
static FormatFunc	format_funcs[128] = {0};

static void	put_char(const char *c)
{
	write(1, c, 1);
}


int					format_char(va_list *args);
int					ft_printf(char const *format, ...);
