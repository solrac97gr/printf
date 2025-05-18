/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:04:46 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/17 21:24:32 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Converts an unsigned integer to its string representation and prints it.
 * 
 * This function recursively converts the given unsigned integer to its string
 * representation, printing each digit as it is determined. It returns the total
 * number of characters printed.
 * 
 * @param n The unsigned integer to be converted and printed.
 * @return The number of characters printed.
 */
static int	put_unsigned(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += put_unsigned(n / 10);
	c = (n % 10) + '0';
	ft_put_char(&c);
	count++;
	return (count);
}

/**
 * @brief Formats and prints an unsigned integer.
 * 
 * This function retrieves an unsigned integer from the argument list,
 * converts it to its string representation, and prints it. It returns the
 * number of characters printed.
 * 
 * @param args A pointer to a va_list containing the arguments.
 * @return The number of characters printed.
 */
int	format_unsigned(va_list *args)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	return (put_unsigned(n));
}
