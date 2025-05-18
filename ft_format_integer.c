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

/**
 * @brief Converts a long integer to its string representation and prints it.
 * 
 * This function recursively converts the given long integer to its string
 * representation, printing each digit as it is determined. It handles negative
 * numbers by printing a '-' sign before the number. It returns the total number
 * of characters printed.
 * 
 * @param n The long integer to be converted and printed.
 * @return The number of characters printed.
 */
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

/**
 * @brief Formats and prints an integer.
 * 
 * This function retrieves an integer from the argument list, converts it to its
 * string representation, and prints it. It returns the number of characters
 * printed.
 * 
 * @param args A pointer to a va_list containing the arguments.
 * @return The number of characters printed.
 */
int	format_integer(va_list *args)
{
	int	n;

	n = va_arg(*args, int);
	return (put_nbr(n));
}
