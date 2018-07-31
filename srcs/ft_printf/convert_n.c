/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:56:23 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 14:56:26 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <inttypes.h>
#include <stddef.h>

int			convert_n(char **str, t_form *fp, va_list *va)
{
	intmax_t	*ptr;

	*str = ft_strnew(0);
	ptr = (intmax_t *)va_arg(*va, void *);
	if (fp->lmod_z)
		*ptr = (size_t)fp->count;
	else if (fp->lmod_j)
		*ptr = (intmax_t)fp->count;
	else if (fp->lmod_t)
		*ptr = (ptrdiff_t)fp->count;
	else if (fp->lmod_ll)
		*ptr = (long long)fp->count;
	else if (fp->lmod_l)
		*ptr = (long)fp->count;
	else if (fp->lmod_h)
		*ptr = (short)fp->count;
	else if (fp->lmod_hh)
		*ptr = (char)fp->count;
	else
		*ptr = fp->count;
	return (0);
}
