/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_wildcard.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:56:49 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 14:56:50 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_wildcard(t_form *fp, va_list *va, int precision)
{
	int		width;

	width = va_arg(*va, int);
	if (precision)
	{
		if (width >= 0)
			fp->precision = width;
	}
	else
	{
		if (width >= 0)
			fp->min_w = width;
		else
		{
			fp->min_w = width * -1;
			fp->f_just = 1;
		}
	}
	return (0);
}
