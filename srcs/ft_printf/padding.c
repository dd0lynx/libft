/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:57:07 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 14:57:10 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	padzero(t_form *fp, char **str, char *pad, int n)
{
	ft_memset(pad, '0', n);
	if (((fp->d_type == 'x' || fp->d_type == 'X') && fp->f_alt) ||
		fp->d_type == 'p')
		*str = ft_strinsert(*str, pad, 2);
	else if ((fp->d_type == 'd' || fp->d_type == 'i') &&
		(**str == '-' || **str == '+' || **str == ' '))
		*str = ft_strinsert(*str, pad, 1);
	else
		*str = ft_padstr_f(*str, n, '0');
	free(pad);
}

int		pad_str(char **str, int len, t_form *fp)
{
	char	*pad;
	int		n;

	n = fp->min_w - len;
	pad = ft_strnew(n);
	if (fp->f_just)
	{
		ft_memset(pad, ' ', n);
		*str = ft_memjoin_free(*str, pad, len, n);
	}
	else if (fp->f_zero && ft_strchr("dixp", fp->d_type) &&
		(!(fp->min_w > fp->precision) || fp->precision < 0))
		padzero(fp, str, pad, n);
	else if (fp->f_zero && !ft_strchr("dixp", fp->d_type))
	{
		ft_memset(pad, '0', n);
		*str = ft_memjoin_free(pad, *str, n, len);
	}
	else
	{
		ft_memset(pad, ' ', n);
		*str = ft_memjoin_free(pad, *str, n, len);
	}
	return (n);
}
