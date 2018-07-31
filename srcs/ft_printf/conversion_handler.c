/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:50:28 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 14:58:19 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_conversion(char **str, t_form *fp, va_list *va)
{
	int		n;

	n = 0;
	if (fp->d_type == '%')
	{
		*str = ft_strdup("%");
		n = 1;
	}
	else if (fp->d_type == 'd' || fp->d_type == 'i')
		n = convert_int(str, fp, va);
	else if (fp->d_type == 'u' || fp->d_type == 'o' || fp->d_type == 'x')
		n = convert_uint(str, fp, va);
	else if (fp->d_type == 's')
		n = convert_str(str, fp, va);
	else if (fp->d_type == 'c')
		n = convert_char(str, fp, va);
	else if (fp->d_type == 'p')
		n = convert_ptr(str, fp, va);
	else if (fp->d_type == 'n')
		n = convert_n(str, fp, va);
	else
		*str = ft_strnew(0);
	return (n);
}

int			convert_arg(t_form *fp, va_list *va)
{
	char	*str;
	int		s_len;

	if ((s_len = get_conversion(&str, fp, va)) == -1)
		return (0);
	if (fp->min_w > s_len)
		s_len += pad_str(&str, s_len, fp);
	fp->buff = ft_memjoin_free(fp->buff, str, fp->count, s_len);
	fp->count += s_len;
	return (1);
}
