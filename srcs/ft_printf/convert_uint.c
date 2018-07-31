/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:56:41 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 14:56:42 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <inttypes.h>
#include <stdlib.h>

int		buildstr_uint(char **str, uintmax_t *arg, t_form *fp)
{
	if (!*arg && !fp->precision)
		*str = ft_strnew(1);
	else if (fp->d_type == 'x')
		*str = ft_uimaxtostr(*arg, 16);
	else if (fp->d_type == 'o')
		*str = ft_uimaxtostr(*arg, 8);
	else
		*str = ft_uimaxtostr(*arg, 10);
	if ((int)ft_strlen(*str) < fp->precision)
		*str = ft_padstr_f(*str, fp->precision - (int)ft_strlen(*str), '0');
	if (fp->f_alt && **str != '0')
	{
		if ((fp->d_type == 'o') && **str != '0')
			*str = ft_padstr_f(*str, 1, '0');
		else if (fp->d_type == 'x' && *arg)
		{
			*str = ft_padstr_f(*str, 1, 'x');
			*str = ft_padstr_f(*str, 1, '0');
		}
	}
	if (fp->f_toupper)
		ft_strupper(*str);
	return ((int)ft_strlen(*str));
}

int		convert_uint(char **str, t_form *fp, va_list *va)
{
	uintmax_t	arg;

	if (fp->lmod_z)
		arg = va_arg(*va, size_t);
	else if (fp->lmod_j)
		arg = va_arg(*va, uintmax_t);
	else if (fp->lmod_ll)
		arg = va_arg(*va, unsigned long long);
	else if (fp->lmod_l || fp->lmod_t)
		arg = va_arg(*va, unsigned long);
	else if (fp->lmod_h)
		arg = (unsigned short)va_arg(*va, unsigned int);
	else if (fp->lmod_hh)
		arg = (unsigned char)va_arg(*va, unsigned int);
	else
		arg = va_arg(*va, unsigned int);
	return (buildstr_uint(str, &arg, fp));
}
