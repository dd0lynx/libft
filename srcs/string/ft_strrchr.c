/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:32:51 by ddowty            #+#    #+#             */
/*   Updated: 2016/11/05 19:35:48 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	char	*p;

	chr = (char)c;
	p = NULL;
	while (*s != '\0')
	{
		if ((char)*s == chr)
			p = (char *)s;
		s++;
	}
	if (chr == '\0')
		p = (char *)s;
	return (p);
}
