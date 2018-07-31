/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:56:06 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 14:56:08 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <stdlib.h>

int		ft_wcharlen(wchar_t chr)
{
	int		n;

	if (chr <= 0x7F)
		n = 1;
	else if (chr <= 0x7FF)
		n = 2;
	else if (chr <= 0xFFFF)
		n = 3;
	else if (chr <= 0x10FFFF)
		n = 4;
	else
		n = 1;
	return (n);
}

char	*ft_wchartostr(wchar_t chr, int n)
{
	char	*new;

	new = ft_strnew(n);
	if (n == 1)
		new[0] = chr;
	else if (n >= 2)
	{
		new[0] = (chr >> 6) + 0xC0;
		new[1] = (chr & 0x3F) + 0x80;
	}
	else if (n == 3)
	{
		new[0] = (chr >> 12) + 0xE0;
		new[1] = ((chr >> 6) & 0x3F) + 0x80;
		new[2] = (chr & 0x3F) + 0x80;
	}
	else if (n == 4)
	{
		new[0] = (chr >> 18) + 0xF0;
		new[1] = ((chr >> 12) & 0x3F) + 0x80;
		new[2] = ((chr >> 6) & 0x3F) + 0x80;
		new[3] = (chr & 0x3F) + 0x80;
	}
	return (new);
}

int		convert_wchar(char **str, va_list *va)
{
	wchar_t	c;
	int		n;

	c = (wchar_t)va_arg(*va, wint_t);
	if ((n = ft_wcharlen(c)) > MB_CUR_MAX)
		return (-1);
	*str = ft_wchartostr(c, n);
	return (n);
}

int		convert_char(char **str, t_form *fp, va_list *va)
{
	int		n;

	n = 0;
	if (fp->lmod_l && MB_CUR_MAX > 1)
	{
		if ((n = convert_wchar(str, va)) == -1)
			return (-1);
	}
	else
	{
		n = 1;
		*str = ft_strnew(1);
		**str = (char)va_arg(*va, int);
	}
	return (n);
}
