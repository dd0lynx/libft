/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:44:13 by ddowty            #+#    #+#             */
/*   Updated: 2016/11/05 19:39:19 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		len;
	int		n;
	char	*p;
	char	*s;

	n = size;
	p = dst;
	s = (char *)src;
	while (*p != '\0' && n-- != 0)
		p++;
	len = p - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen((char *)src));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*p++ = *s;
			n--;
		}
		s++;
	}
	*p = '\0';
	return (len + (s - src));
}
