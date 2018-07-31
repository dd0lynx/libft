/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 23:36:47 by ddowty            #+#    #+#             */
/*   Updated: 2016/11/27 23:46:26 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_ofd
{
	int				fd;
	char			*buff;
	struct s_ofd	*next;
}					t_ofd;

int					get_next_line(int fd, char **line);
#endif
