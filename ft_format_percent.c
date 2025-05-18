/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:04:46 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/17 21:24:55 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Formats and prints a percent sign.
 * 
 * This function prints a percent sign to the standard output
 * and returns the number of characters printed (always 1).
 * 
 * @param args A pointer to a va_list containing the arguments.
 * @return The number of characters printed (always 1 for a percent sign).
 */
int	format_percent(va_list *args)
{
	char	c;

	(void)args;
	c = '%';
	ft_put_char(&c);
	return (1);
}
