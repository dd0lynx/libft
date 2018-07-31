/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:55:51 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 14:55:54 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <inttypes.h>

int		convert_ptr(char **str, t_form *fp, va_list *va)
{
	uintmax_t	num;

	num = (uintmax_t)va_arg(*va, void *);
	if (num || fp->precision != 0)
		*str = ft_uimaxtostr(num, 16);
	else
		*str = ft_strnew(0);
	if ((int)ft_strlen(*str) < fp->precision)
		*str = ft_padstr_f(*str, fp->precision - (int)ft_strlen(*str), '0');
	*str = ft_padstr_f(*str, 1, 'x');
	*str = ft_padstr_f(*str, 1, '0');
	return ((int)ft_strlen(*str));
}
