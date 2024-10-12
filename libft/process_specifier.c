/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:44:57 by kyukang           #+#    #+#             */
/*   Updated: 2024/08/15 15:17:01 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	process_specifier(va_list *args, char spec)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += print_char(va_arg(*args, int));
	else if (spec == 's')
		count += print_str(va_arg(*args, char *));
	else if (spec == 'p')
		count += print_ptr(va_arg(*args, void *));
	else if (spec == 'd' || spec == 'i')
		count += print_dec(va_arg(*args, int));
	else if (spec == 'u')
		count += print_dec((unsigned int)va_arg(*args, unsigned int));
	else if (spec == 'x')
		count += print_hexa(va_arg(*args, unsigned int), 0);
	else if (spec == 'X')
		count += print_hexa(va_arg(*args, unsigned int), 1);
	else if (spec == '%')
		count += print_char('%');
	return (count);
}
