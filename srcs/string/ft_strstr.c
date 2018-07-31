/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:44:06 by ddowty            #+#    #+#             */
/*   Updated: 2016/11/05 19:51:53 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	len;

	if (!*little)
		return ((char *)big);
	len = ft_strlen((char *)little);
	while (*big != '\0')
	{
		if (*big == *little)
			if (!ft_strncmp(little, big, len))
				return ((char *)big);
		big++;
	}
	return (NULL);
}
