/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:44:22 by kyukang           #+#    #+#             */
/*   Updated: 2024/08/15 15:18:07 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hexa(unsigned long long num, int uppercase)
{
	char	buffer[65];
	char	*digit;
	char	*ptr;

	if (uppercase)
		digit = "0123456789ABCDEF";
	else
		digit = "0123456789abcdef";
	ptr = buffer + 64;
	*ptr = '\0';
	if (num == 0)
		*(--ptr) = '0';
	else
	{
		while (num > 0)
		{
			*(--ptr) = digit[num % 16];
			num /= 16;
		}
	}
	return (print_str(ptr));
}
