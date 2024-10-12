/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:44:09 by kyukang           #+#    #+#             */
/*   Updated: 2024/08/15 15:18:07 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_dec(long long num)
{
	long long	n;
	int			len;

	n = num;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		len += print_dec(n / 10);
		len += print_dec(n % 10);
	}
	if (n < 10)
		len += print_char(n + 48);
	return (len);
}
