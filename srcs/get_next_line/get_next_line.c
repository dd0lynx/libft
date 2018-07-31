/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 23:37:17 by ddowty            #+#    #+#             */
/*   Updated: 2016/11/27 23:48:12 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static size_t	ft_hasln(const char *str)
{
	size_t	n;

	n = 0;
	while (*str)
	{
		n++;
		if (*str == '\n')
			return (n);
		str++;
	}
	return (0);
}

static void		ft_freeln(char **buff, char *buff2)
{
	size_t	i;
	char	*temp;

	i = 0;
	free(buff2);
	temp = *buff;
	while ((*buff)[i] != '\0')
	{
		if ((*buff)[i++] == '\n')
			break ;
	}
	if (i == ft_strlen(*buff))
	{
		free(temp);
		*buff = NULL;
	}
	else
	{
		*buff = ft_strcut_end(*buff, i);
		free(temp);
	}
}

static char		*ft_getln(int fd, char **buff1)
{
	size_t	i;
	char	*buff2;
	char	*temp;

	i = 0;
	buff2 = ft_strnew(BUFF_SIZE);
	if (!(i = ft_hasln(*buff1)))
		while ((read(fd, buff2, BUFF_SIZE)) > 0)
		{
			temp = *buff1;
			*buff1 = (ft_strjoin(*buff1, buff2));
			ft_bzero(buff2, BUFF_SIZE + 1);
			free(temp);
			if ((i = ft_hasln(*buff1)))
			{
				temp = ft_strsub(*buff1, 0, i - 1);
				break ;
			}
		}
	else
		temp = ft_strsub(*buff1, 0, i - 1);
	if (!i)
		temp = ft_strdup(*buff1);
	ft_freeln(buff1, buff2);
	return (temp);
}

static t_ofd	*ft_getfd(int fd)
{
	static t_ofd	root;
	t_ofd			*p;

	p = &root;
	if (!p->fd)
		p->fd = fd;
	else if (p->fd != fd)
	{
		while (p->next)
		{
			p = p->next;
			if (p->fd == fd)
				return (p);
		}
		p->next = (t_ofd *)malloc(sizeof(t_ofd));
		ft_bzero(p->next, sizeof(t_ofd));
		p->next->fd = fd;
		p = p->next;
	}
	return (p);
}

int				get_next_line(const int fd, char **line)
{
	t_ofd			*node;

	if (!line)
		return (-1);
	node = ft_getfd(fd);
	if (!node->buff)
	{
		node->buff = ft_strnew(BUFF_SIZE);
	}
	if (!*(node->buff))
		if (!(read(fd, node->buff, BUFF_SIZE) >= 0))
			return (-1);
	if (*(node->buff))
	{
		*line = ft_getln(fd, &(node->buff));
		return (1);
	}
	else
		return (0);
}
