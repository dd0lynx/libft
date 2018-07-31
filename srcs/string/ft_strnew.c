/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 00:06:51 by ddowty            #+#    #+#             */
/*   Updated: 2018/05/16 00:16:50 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_strnew(size_t size)
{
	char	*p;
	size_t	i;

	if ((p = (char *)malloc(size + 1)) != NULL)
	{
		i = 0;
		while (i < size)
			p[i++] = '\0';
		p[i] = '\0';
	}
	return ((void *)p);
}
