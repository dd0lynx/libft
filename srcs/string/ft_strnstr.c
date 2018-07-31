/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 01:35:07 by ddowty            #+#    #+#             */
/*   Updated: 2016/11/04 21:14:59 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l;

	if (!*little)
		return ((char *)big);
	l = ft_strlen((char *)little);
	while (*big != '\0' && len-- >= l)
	{
		if (*big == *little)
			if (!ft_strncmp(little, big, l))
				return ((char *)big);
		big++;
	}
	return (NULL);
}
