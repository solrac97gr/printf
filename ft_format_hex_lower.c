/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex_lower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:04:46 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/17 20:25:06 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_hex_lower(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 16)
		count += put_hex_lower(n / 16);
	if ((n % 16) < 10)
		c = (n % 16) + '0';
	else
		c = (n % 16) - 10 + 'a';
	put_char(&c);
	count++;
	return (count);
}

int	format_hex_lower(va_list *args)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	return (put_hex_lower(n));
}
