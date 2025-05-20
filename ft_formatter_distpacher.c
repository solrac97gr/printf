/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter_distpacher.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:04:46 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/19 18:28:04 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Maximum value for format functions (ascii value of 'x')
#define MAX_FORMAT_FUNC 'x'

/**

 * @brief Returns the appropriate formatting function based on the specifier.
 *
 * This function takes a character representing a format specifier and returns
 * the corresponding formatting function. If the specifier is not recognized,
 * it returns NULL.
 *
 * @param specifier The format specifier character.
 * @return A pointer to the corresponding formatting function,
	or NULL if not found.
 */
t_FormatFunc	get_format_func(char specifier)
{
	static t_FormatFunc	format_funcs[MAX_FORMAT_FUNC + 1] = {
	['c'] = format_char,
	['s'] = format_string,
	['p'] = format_pointer,
	['d'] = format_integer,
	['i'] = format_integer,
	['u'] = format_unsigned,
	['x'] = format_hex_lower,
	['X'] = format_hex_upper,
	['%'] = format_percent,
	};

	if (specifier < 0 || specifier > MAX_FORMAT_FUNC)
		return (NULL);
	return (format_funcs[(unsigned char)specifier]);
}
