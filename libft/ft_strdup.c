/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:40:21 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/23 17:03:03 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(ft_strlen(str) + 5);
	if (dup == NULL)
		return (NULL);
	else
	{
		while (str[i])
		{
			dup[i] = str[i];
			i++;
		}
		dup[i] = '\0';
		dup[i + 1] = '\0';
		return (dup);
	}
}
