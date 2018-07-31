/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:56:59 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 14:57:00 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	init_t_form(t_form *fp)
{
	fp->f_just = 0;
	fp->f_plus = 0;
	fp->f_space = 0;
	fp->f_alt = 0;
	fp->f_zero = 0;
	fp->f_toupper = 0;
	fp->lmod_h = 0;
	fp->lmod_hh = 0;
	fp->lmod_l = 0;
	fp->lmod_ll = 0;
	fp->lmod_j = 0;
	fp->lmod_z = 0;
	fp->lmod_t = 0;
	fp->lmod_ldouble = 0;
	fp->min_w = 0;
	fp->precision = -1;
	fp->d_type = 0;
}

static void	init_t_txt_mod(t_txt_mod *t_mods)
{
	t_mods->color = 0;
	t_mods->c256 = 0;
	t_mods->bold = 0;
	t_mods->italic = 0;
	t_mods->underline = 0;
	t_mods->open = 0;
}

char		*ft_parse(const char *format, t_form *fp, va_list *va)
{
	format = get_form(format, fp, va);
	if (!convert_arg(fp, va))
	{
		ft_strdel(&fp->buff);
		fp->count = -1;
		return (0);
	}
	init_t_form(fp);
	return ((char *)format);
}

int			ft_printf(const char *format, ...)
{
	va_list va;
	t_form	fp;

	fp.count = 0;
	fp.buff = ft_strnew(1);
	init_t_form(&fp);
	init_t_txt_mod(&fp.t_mod);
	va_start(va, format);
	while (format && *format)
	{
		if (*format == '{')
			format = convert_txt_mod(format, &fp);
		if (*format == '%')
			format = ft_parse(format + 1, &fp, &va);
		else
		{
			fp.buff = ft_memjoin_free(fp.buff, ft_strdup(format), fp.count, 1);
			fp.count++;
			format++;
		}
	}
	va_end(va);
	write(1, fp.buff, fp.count);
	return (fp.count);
}
