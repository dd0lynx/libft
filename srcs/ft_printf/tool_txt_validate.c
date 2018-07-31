/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_txt_validate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:58:09 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 14:58:10 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*grab_arg(const char *format)
{
	int		i;

	i = 0;
	while (*(format + i) != '}' && *(format + i) != '\0')
		i++;
	return (ft_strsub(format, 0, i));
}

static int	if_color(const char *format, char **arg)
{
	if (!*arg)
		*arg = grab_arg(format);
	if (ft_strequ("black", *arg) || ft_strequ("red", *arg) ||
		ft_strequ("green", *arg) || ft_strequ("yellow", *arg) ||
		ft_strequ("blue", *arg) || ft_strequ("magenta", *arg) ||
		ft_strequ("cyan", *arg) || ft_strequ("gray", *arg) ||
		ft_strequ("darg gray", *arg) || ft_strequ("light red", *arg) ||
		ft_strequ("light green", *arg) || ft_strequ("light yellow", *arg) ||
		ft_strequ("light blue", *arg) || ft_strequ("light magenta", *arg) ||
		ft_strequ("light cyan", *arg) || ft_strequ("white", *arg))
		return (1);
	else if (ft_atoi(*arg) > 0 || **arg == '0')
		return (2);
	else
		return (0);
}

static int	if_format(const char *format, char **arg)
{
	if (!*arg)
		*arg = grab_arg(format);
	if (ft_strequ("bold", *arg) || ft_strequ("italic", *arg) ||
		ft_strequ("underline", *arg))
		return (3);
	else
		return (0);
}

static int	if_closed(const char *format, char **arg)
{
	int		ret;

	ret = 0;
	if (!*arg)
	{
		if (*format == '/')
		{
			*arg = grab_arg(format + 1);
			if ((ret = if_color(format, arg)))
				return (ret);
			else if ((ret = if_format(format, arg)))
				return (ret);
			else if (*arg)
				ft_strdel(arg);
		}
	}
	else
		while (*format)
		{
			if (*format == '{' && *(format + 1) == '/')
				if (!ft_strncmp(*arg, format + 2, ft_strlen(*arg)))
					return (1);
			format++;
		}
	return (0);
}

int			valid_mod(const char *format, t_txt_mod *t_mod)
{
	char	*arg;
	int		i;

	arg = 0;
	if ((i = if_closed(format + 1, &arg)))
	{
		if (!t_mod->open)
			return (0);
		i = reset_arg(arg, i, t_mod);
	}
	else if ((i = if_color(format + 1, &arg)) && if_closed(format + 1, &arg))
		i = set_color(arg, i, t_mod);
	else if ((i = if_format(format + 1, &arg)) && if_closed(format + 1, &arg))
		i = set_format(arg, i, t_mod);
	else
		return (0);
	return (i);
}
