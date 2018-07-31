/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 12:12:17 by ddowty            #+#    #+#             */
/*   Updated: 2016/11/04 00:41:00 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recput(long nb)
{
	if (nb != 0)
	{
		ft_recput(nb / 10);
		nb %= 10;
		ft_putchar(nb + '0');
	}
}

void		ft_putnbr(int nb)
{
	long n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n == 0)
		ft_putchar('0');
	else
		ft_recput(n);
}
