/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex_lower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:04:46 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/19 18:13:32 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Converts an unsigned integer to its hexadecimal representation
 *        in lowercase and prints it.
 * 
 * This function recursively converts the given unsigned integer to its
 * hexadecimal representation in lowercase, printing each digit as it is
 * determined. It returns the total number of characters printed.
 * 
 * @param n The unsigned integer to be converted and printed.
 * @return The number of characters printed.
 */
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
	ft_put_char(&c);
	count++;
	return (count);
}

/**
 * @brief Formats and prints an unsigned integer in hexadecimal format.
 * 
 * This function retrieves an unsigned integer from the argument list,
 * converts it to its hexadecimal representation in lowercase, and prints it.
 * It returns the number of characters printed.
 * 
 * @param args A pointer to a va_list containing the arguments.
 * @return The number of characters printed.
 */
int	format_hex_lower(va_list *args)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	return (put_hex_lower(n));
}
