/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_txt_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:57:57 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 14:57:59 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	reset_color(char *arg, int i, t_txt_mod *t_mod)
{
	if (i == 1)
		t_mod->color = 0;
	else if (i == 2)
	{
		t_mod->c256 = 0;
		t_mod->color = 0;
	}
	i = (int)ft_strlen(arg) + 3;
	return (i);
}

static int	reset_format(char *arg, int i, t_txt_mod *t_mod)
{
	if (ft_strequ("bold", arg))
		t_mod->bold = 0;
	else if (ft_strequ("italic", arg))
		t_mod->italic = 0;
	else if (ft_strequ("underline", arg))
		t_mod->underline = 0;
	i = (int)ft_strlen(arg) + 3;
	return (i);
}

int			reset_arg(char *arg, int i, t_txt_mod *t_mod)
{
	if (i == 1 || i == 2)
		i = reset_color(arg, i, t_mod);
	else
		i = reset_format(arg, i, t_mod);
	t_mod->open = 0;
	return (i);
}
