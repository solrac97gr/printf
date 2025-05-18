/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:04:46 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/17 21:23:45 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Formats and prints a character.
 * 
 * This function retrieves a character from the argument list,
 * prints it to the standard output, and returns the number of characters printed.
 * 
 * @param args A pointer to a va_list containing the arguments.
 * @return The number of characters printed (always 1 for a single character).
 */
int	format_char(va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	ft_put_char(&c);
	return (1);
}
