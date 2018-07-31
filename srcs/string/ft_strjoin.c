/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 21:21:55 by ddowty            #+#    #+#             */
/*   Updated: 2016/11/05 22:17:55 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*new;

	if (!(s1 && s2))
		return (NULL);
	i = 0;
	new = (char *)malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2)) + 1);
	if (!new)
		return (new);
	if (s1)
		while (*s1 != '\0')
		{
			new[i] = *s1;
			i++;
			s1++;
		}
	if (s2)
		while (*s2 != '\0')
		{
			new[i] = *s2;
			i++;
			s2++;
		}
	new[i] = '\0';
	return (new);
}
