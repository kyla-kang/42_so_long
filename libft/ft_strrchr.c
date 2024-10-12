/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:04:12 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/03 18:31:11 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*end;

	end = NULL;
	while (*s)
	{
		if (*s == (char)c)
			end = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (end);
}
