/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_txt_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:57:43 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 14:57:45 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			set_format(char *arg, int i, t_txt_mod *t_mod)
{
	if (ft_strequ("bold", arg))
		t_mod->bold = 1;
	else if (ft_strequ("italic", arg))
		t_mod->italic = 1;
	else if (ft_strequ("underline", arg))
		t_mod->underline = 1;
	i = (int)ft_strlen(arg) + 2;
	return (i);
}
