/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:39:09 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/25 10:45:15 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_count_for_base_m(intmax_t n, int base)
{
	long int	i;

	i = 0;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char		ft_set_base(int n)
{
	char c;

	if (ft_isdigit(n) == 1)
		c = (char)n;
	else
		c = n + 39;
	return (c);
}

char		*ft_itoa_base(intmax_t n, int base)
{
	long int		i;
	int				j;
	uintmax_t		nb;
	char			*str;

	j = 1;
	nb = n;
	i = ft_count_for_base_m(n, base);
	str = (char *)ft_memalloc(i + 3);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		nb = -n;
		str[0] = '-';
		j = 0;
	}
	while (i > 0)
	{
		str[i-- - j] = ft_set_base((nb % base) + 48);
		nb = nb / base;
	}
	return (str);
}
