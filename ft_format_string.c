/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:04:46 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/17 21:23:57 by carloga2         ###   ########.fr       */
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
int	format_string(va_list *args)
{
	char	*str;
	int		count;

	count = 0;
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_put_char(str);
		str++;
		count++;
	}
	return (count);
}
