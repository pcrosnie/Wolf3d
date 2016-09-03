/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:42:06 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/09/03 11:08:49 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	n;

	i = 0;
	nb = 0;
	n = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == 45)
	{
		if (str[i + 1] == '+' || str[i - 1] == '+')
			return (0);
		n = i;
		i++;
	}
	(str[i] == '+') ? i++ : 0;
	while (str[i] <= 57 && str[i] >= 48 && str[i])
		nb = nb * 10 + str[i++] - 48;
	if (str[n] == 45)
		nb = -nb;
	return (nb);
}
