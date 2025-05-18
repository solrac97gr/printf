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

/**
 * @brief Prints a string to the standard output.
 * 
 * This function takes a string as input and prints it character by character
 * 
 * @param str The string to be printed.
 */
static void	put_str(const char *str)
{
	while (*str)
		write(1, str++, 1);
}

/**
 * @brief Converts an unsigned long integer to its hexadecimal representation
 *        and prints it.
 * 
 * This function recursively converts the given unsigned long integer to its
 * hexadecimal representation, printing each digit as it is determined. It
 * returns the total number of characters printed.
 * 
 * @param n The unsigned long integer to be converted and printed.
 * @return The number of characters printed.
 */
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

/**
 * @brief Formats and prints a pointer address.
 * 
 * This function retrieves a pointer from the argument list, converts it to its
 * hexadecimal representation, and prints it. If the pointer is NULL, it prints
 * "(nil)". It returns the number of characters printed.
 * 
 * @param args A pointer to a va_list containing the arguments.
 * @return The number of characters printed.
 */
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
