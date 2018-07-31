/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_txt_mods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:57:50 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 14:57:52 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	adds a string matching this format "\033[(';' seperated list of args)m"
**	multiple unclosed colors undefined.
*/

static char	*add_arg(char *str, int n)
{
	char	*arg;

	arg = ft_itoa(n);
	if (!str)
		str = arg;
	else
	{
		str = ft_padstr_e(str, 1, ';');
		str = ft_strjoin_free(str, arg);
	}
	return (str);
}

static char	*get_args(t_txt_mod *new, t_txt_mod *old)
{
	char	*str;

	str = 0;
	if (new->c256 != old->c256)
		str = ft_strjoin_free(ft_strdup("38;5;"),
			ft_strdup(ft_itoa(new->color)));
	else if (new->color != old->color)
		str = ft_strdup(ft_itoa(new->color));
	if (new->bold && new->bold != old->bold)
		str = add_arg(str, new->bold);
	if (new->italic && new->italic != old->italic)
		str = add_arg(str, new->italic);
	if (new->underline && new->underline != old->underline)
		str = add_arg(str, new->underline);
	str = ft_padstr_e(str, 1, 'm');
	return (str);
}

char		*convert_txt_mod(const char *format, t_form *fp)
{
	char		*strmod;
	int			i;
	t_txt_mod	temp;

	temp.color = fp->t_mod.color;
	temp.c256 = fp->t_mod.c256;
	temp.bold = fp->t_mod.bold;
	temp.italic = fp->t_mod.italic;
	temp.underline = fp->t_mod.underline;
	if (!(i = valid_mod(format, &fp->t_mod)))
		return ((char *)format);
	strmod = ft_strdup("\033[");
	strmod = ft_strjoin_free(strmod, get_args(&fp->t_mod, &temp));
	if (strmod)
	{
		fp->buff = ft_memjoin_free(fp->buff, strmod,
			fp->count, ft_strlen(strmod));
		fp->count += ft_strlen(strmod);
	}
	return ((char *)format + i);
}
