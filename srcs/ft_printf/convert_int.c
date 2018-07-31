/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:56:15 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 14:56:17 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <inttypes.h>
#include <stddef.h>

static char	*precision_n(char *str, t_form *fp)
{
	char	*temp;
	char	*temp2;

	temp = str;
	temp2 = ft_strnew(0);
	temp2 = ft_padstr_f(temp2, fp->precision - (int)ft_strlen(str) + 1, '0');
	str = ft_strinsert(str, temp2, 1);
	free(temp);
	free(temp2);
	return (str);
}

int			buildstr_int(char **str, intmax_t *arg, t_form *fp)
{
	if (*arg == 0 && !fp->precision)
		*str = ft_strnew(0);
	else
		*str = ft_imaxtostr(*arg);
	if (*arg < 0 && ((int)ft_strlen(*str) - 1) < fp->precision)
		*str = precision_n(*str, fp);
	else if ((int)ft_strlen(*str) < fp->precision)
		*str = ft_padstr_f(*str, fp->precision - (int)ft_strlen(*str), '0');
	if (fp->f_plus && *arg >= 0)
		*str = ft_padstr_f(*str, 1, '+');
	else if (fp->f_space && *arg >= 0)
		*str = ft_padstr_f(*str, 1, ' ');
	return ((int)ft_strlen(*str));
}

int			convert_int(char **str, t_form *fp, va_list *va)
{
	intmax_t	arg;

	if (fp->lmod_z)
		arg = va_arg(*va, size_t);
	else if (fp->lmod_j)
		arg = va_arg(*va, intmax_t);
	else if (fp->lmod_t)
		arg = va_arg(*va, ptrdiff_t);
	else if (fp->lmod_ll)
		arg = va_arg(*va, long long);
	else if (fp->lmod_l)
		arg = va_arg(*va, long);
	else if (fp->lmod_h)
		arg = (short)va_arg(*va, int);
	else if (fp->lmod_hh)
		arg = (char)va_arg(*va, int);
	else
		arg = va_arg(*va, int);
	return (buildstr_int(str, &arg, fp));
}
