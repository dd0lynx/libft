/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:57:18 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 14:57:20 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_type(const char *format, t_form *fp)
{
	if (*format != '\0' && ft_strchr("%dDiuUoOxXfFeEgGaAcCsSpn", *format))
	{
		fp->d_type = *format;
		if (ft_strchr("DUOCS", *format))
		{
			fp->d_type = ft_tolower(fp->d_type);
			fp->lmod_l = 1;
		}
		else if (ft_strchr("XFEGA", *format))
		{
			fp->d_type = ft_tolower(fp->d_type);
			fp->f_toupper = 1;
		}
		return (1);
	}
	return (0);
}

int			set_num(const char *format, t_form *fp, int p)
{
	int		n;

	n = 0;
	if (p)
		fp->precision = ft_atoi(format);
	else
		fp->min_w = ft_atoi(format);
	while (*(format + n + 1) >= '0' && *(format + n + 1) <= '9')
		n++;
	return (n);
}

int			get_width(const char *format, t_form *fp, va_list *va)
{
	int		n;

	n = 1;
	if (*format == '*')
		n += convert_wildcard(fp, va, 0);
	else if (*format >= '0' && *format <= '9')
		n += set_num(format, fp, 0);
	else if (*format == '.')
	{
		n = 2;
		if (*(format + 1) == '*')
			n += convert_wildcard(fp, va, 1);
		else if (*(format + 1) >= '0' && *(format + 1) <= '9')
			n += set_num(format + 1, fp, 1);
		else
		{
			n--;
			fp->precision = 0;
		}
	}
	else
		return (-1);
	return (n);
}

int			get_flag(const char *format, t_form *fp)
{
	if (*format == '-')
		fp->f_just = 1;
	else if (*format == '#')
		fp->f_alt = 1;
	else if (*format == '+')
		fp->f_plus = 1;
	else if (*format == ' ')
		fp->f_space = 1;
	else if (*format == '0')
		fp->f_zero = 1;
	else
		return (0);
	return (1);
}

char		*get_form(const char *format, t_form *fp, va_list *va)
{
	int		n;

	while (*format)
	{
		if ((n = get_flag(format, fp)))
			format += n;
		else if ((n = get_length(format, fp)))
			format += n;
		else if ((n = get_width(format, fp, va)) >= 0)
			format += n;
		else if ((n = get_type(format, fp)))
		{
			format += n;
			break ;
		}
		else
			break ;
	}
	return ((char *)format);
}
