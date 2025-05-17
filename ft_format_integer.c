/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:04:46 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/17 21:24:25 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_nbr(long n)
{
	int		count;
	char	c;

	count = 0;
	if (n < 0)
	{
		c = '-';
		ft_put_char(&c);
		count++;
		n = -n;
	}
	if (n >= 10)
		count += put_nbr(n / 10);
	c = (n % 10) + '0';
	ft_put_char(&c);
	count++;
	return (count);
}

int	format_integer(va_list *args)
{
	int	n;

	n = va_arg(*args, int);
	return (put_nbr(n));
}
