/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:04:46 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/17 21:24:05 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_str(const char *str)
{
	while (*str)
		write(1, str++, 1);
}

static int	put_hex(unsigned long n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 16)
		count += put_hex(n / 16);
	if ((n % 16) < 10)
		c = (n % 16) + '0';
	else
		c = (n % 16) - 10 + 'a';
	ft_put_char(&c);
	count++;
	return (count);
}

int	format_pointer(va_list *args)
{
	void			*ptr;
	unsigned long	addr;
	int				count;

	count = 0;
	ptr = va_arg(*args, void *);
	addr = (unsigned long)ptr;
	if (addr == 0)
	{
		put_str("(nil)");
		count += 5;
	}
	else
	{
		put_str("0x");
		count += 2;
		count += put_hex(addr);
	}
	return (count);
}
