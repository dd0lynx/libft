/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_txt_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:57:37 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 14:57:38 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_c256(char *arg)
{
	return (ft_atoi(arg));
}

static int	set_c16_2(char *arg)
{
	if (ft_strequ("dark gray", arg))
		return (90);
	else if (ft_strequ("light red", arg))
		return (91);
	else if (ft_strequ("light green", arg))
		return (92);
	else if (ft_strequ("light yellow", arg))
		return (93);
	else if (ft_strequ("light blue", arg))
		return (94);
	else if (ft_strequ("light magenta", arg))
		return (95);
	else if (ft_strequ("light cyan", arg))
		return (96);
	else if (ft_strequ("white", arg))
		return (97);
	else
		return (0);
}

static int	set_c16(char *arg)
{
	if (ft_strequ("black", arg))
		return (30);
	else if (ft_strequ("red", arg))
		return (31);
	else if (ft_strequ("green", arg))
		return (32);
	else if (ft_strequ("yellow", arg))
		return (33);
	else if (ft_strequ("blue", arg))
		return (34);
	else if (ft_strequ("magenta", arg))
		return (35);
	else if (ft_strequ("cyan", arg))
		return (36);
	else if (ft_strequ("gray", arg))
		return (37);
	else
		return (set_c16_2(arg));
}

int			set_color(char *arg, int i, t_txt_mod *t_mod)
{
	if (i == 1)
	{
		t_mod->c256 = 0;
		t_mod->color = set_c16(arg);
	}
	else if (i == 2)
	{
		t_mod->c256 = 1;
		t_mod->color = set_c256(arg);
	}
	t_mod->open = 1;
	i = (int)ft_strlen(arg) + 2;
	return (i);
}
