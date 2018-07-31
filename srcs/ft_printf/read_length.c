/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:57:26 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 14:57:28 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_length(const char *format, t_form *fp)
{
	if (*format == 'h')
	{
		if (*(format + 1) == 'h')
			return ((fp->lmod_hh = 1) + 1);
		else
			return ((fp->lmod_h = 1));
	}
	else if (*format == 'l')
	{
		if (*(format + 1) == 'l')
			return ((fp->lmod_ll = 1) + 1);
		else
			return ((fp->lmod_l = 1));
	}
	else if (*format == 'j')
		return ((fp->lmod_j = 1));
	else if (*format == 'z')
		return ((fp->lmod_z = 1));
	else if (*format == 't')
		return ((fp->lmod_t = 1));
	else if (*format == 'L')
		return ((fp->lmod_ldouble = 1));
	else
		return (0);
}
