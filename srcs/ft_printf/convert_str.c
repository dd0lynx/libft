/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:56:34 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 14:56:35 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <stdlib.h>
#include <locale.h>

static int	ft_wcharlen(wchar_t chr)
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
		n = 0;
	return (n);
}

static int	wstr_len(wchar_t *str)
{
	int		n;
	int		len;

	n = 0;
	while (*str)
	{
		if ((len = ft_wcharlen(*str)) > MB_CUR_MAX)
			return (-1);
		n += len;
		str++;
	}
	return (n);
}

static int	wchartostr(char *str, int i, wchar_t wchr)
{
	if (wchr <= 0x7F || MB_CUR_MAX == 1)
		str[i++] = (wchr);
	else if (wchr <= 0x7FF || MB_CUR_MAX == 2)
	{
		str[i++] = ((wchr >> 6) + 0xC0);
		str[i++] = ((wchr & 0x3F) + 0x80);
	}
	else if (wchr <= 0xFFFF || MB_CUR_MAX == 3)
	{
		str[i++] = ((wchr >> 12) + 0xE0);
		str[i++] = (((wchr >> 6) & 0x3F) + 0x80);
		str[i++] = ((wchr & 0x3F) + 0x80);
	}
	else if (wchr <= 0x10FFFF || MB_CUR_MAX == 4)
	{
		str[i++] = ((wchr >> 18) + 0xF0);
		str[i++] = (((wchr >> 12) & 0x3F) + 0x80);
		str[i++] = (((wchr >> 6) & 0x3F) + 0x80);
		str[i++] = ((wchr & 0x3F) + 0x80);
	}
	return (i);
}

int			convert_wstr(char **str, va_list *va)
{
	wchar_t	*wstr;
	char	*new;
	int		n;
	int		i;

	if (!(wstr = va_arg(*va, wchar_t *)))
	{
		*str = ft_strdup("(null)");
		return (6);
	}
	if ((n = wstr_len(wstr)) == -1)
		return (-1);
	new = ft_strnew(n);
	i = 0;
	while (*wstr)
	{
		n = wstr_len(wstr);
		i = wchartostr(new, i, *wstr);
		wstr++;
	}
	*str = new;
	return (i);
}

int			convert_str(char **str, t_form *fp, va_list *va)
{
	char	*arg;
	int		n;

	if (fp->lmod_l)
	{
		if ((n = convert_wstr(str, va)) == -1)
			return (-1);
	}
	else
	{
		if (!(arg = va_arg(*va, char *)))
			*str = ft_strdup("(null)");
		else
			*str = ft_strdup(arg);
		n = ft_strlen(*str);
	}
	if (fp->precision >= 0 && n > fp->precision)
		n = fp->precision;
	return (n);
}
