/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:49:52 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/06 14:12:14 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*result;
	size_t	strlen;

	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup(""));
	else if (len + start > strlen)
		str = (char *)malloc(strlen - start + 1);
	else
		str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	result = str;
	while (*(s + start) && len)
	{
		*str++ = *(s + start++);
		len--;
	}
	*str = '\0';
	return (result);
}
