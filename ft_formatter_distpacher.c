/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter_distpacher.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:04:46 by carloga2          #+#    #+#             */
/*   Updated: 2025/05/18 11:24:32 by carloga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// The format functions array is declared as static to limit its scope
// to this file. It is initialized with NULL pointers.
// Array size is 256 to cover all possible char values
static t_FormatFunc format_funcs[256] = {0};

/**
 * @brief Initializes the format functions array with the appropriate formatting functions.
 * 
 * This function populates the format_funcs array with pointers to the formatting
 * functions corresponding to each format specifier. It is called only once
 * during the first call to get_format_func_alt.
 */
static void init_format_funcs(void)
{
    format_funcs['c'] = format_char;
    format_funcs['s'] = format_string;
    format_funcs['p'] = format_pointer;
    format_funcs['d'] = format_integer;
    format_funcs['i'] = format_integer;
    format_funcs['u'] = format_unsigned;
    format_funcs['x'] = format_hex_lower;
    format_funcs['X'] = format_hex_upper;
    format_funcs['%'] = format_percent;
}

/**
 * @brief Returns the appropriate formatting function based on the format specifier.
 * 
 * This function takes a character representing a format specifier and returns
 * the corresponding formatting function. If the specifier is not recognized,
 * it returns NULL.
 * 
 * @param specifier The format specifier character.
 * @return A pointer to the corresponding formatting function, or NULL if not found.
 */
t_FormatFunc get_format_func(char specifier)
{
    static int initialized = 0;

    if (!initialized)
    {
        init_format_funcs();
        initialized = 1;
    }
    return format_funcs[(unsigned char)specifier];
}
