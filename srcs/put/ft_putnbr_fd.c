/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 12:15:22 by ddowty            #+#    #+#             */
/*   Updated: 2016/11/04 00:39:24 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recput_fd(long nb, int fd)
{
	if (nb != 0)
	{
		ft_recput_fd(nb / 10, fd);
		nb %= 10;
		ft_putchar_fd(nb + '0', fd);
	}
}

void		ft_putnbr_fd(int nb, int fd)
{
	long n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
		ft_recput_fd(n, fd);
}
