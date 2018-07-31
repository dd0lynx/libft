/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 20:03:23 by ddowty            #+#    #+#             */
/*   Updated: 2016/11/17 23:08:34 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	int			p;
	char		*new;

	if (!s)
		return (NULL);
	i = 0;
	p = start;
	new = (char *)malloc((len * sizeof(char)) + 1);
	if (new != NULL)
	{
		while (i < len)
		{
			new[i] = s[p];
			i++;
			p++;
		}
		new[i] = '\0';
	}
	return (new);
}
