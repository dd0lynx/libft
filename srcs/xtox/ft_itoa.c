/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 01:11:12 by ddowty            #+#    #+#             */
/*   Updated: 2016/11/04 21:16:35 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	basecvrt(long *num)
{
	int		n;

	n = *num % 10;
	*num /= 10;
	return (n);
}

static int	n_places(long num)
{
	int		i;
	long	n;

	i = 0;
	n = num;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*ft_strbuild(long num, int sign)
{
	int		i;
	int		len;
	char	base_t[10];
	char	*s;

	i = 0;
	while (i < 10)
	{
		base_t[i] = i + '0';
		i++;
	}
	len = n_places(num) + sign;
	if (!(s = (char *)malloc((len * sizeof(char)) + 1)))
		return (s);
	s[len] = '\0';
	if (sign > 0)
		s[0] = '-';
	while ((len -= 1) >= 0)
	{
		if (sign == 0 || len != 0)
			s[len] = base_t[basecvrt(&num)];
	}
	return (s);
}

char		*ft_itoa(int value)
{
	long	n;
	int		sign;
	char	*str;

	if (value == 0)
	{
		if (!(str = (char *)malloc(2)))
			return (str);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	n = value;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	str = ft_strbuild(n, sign);
	return (str);
}
