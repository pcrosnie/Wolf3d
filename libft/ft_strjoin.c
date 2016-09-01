/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:09:21 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/16 10:24:28 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = NULL;
	if (s1 && s2)
	{
		str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
		if (!str)
			return (NULL);
		while (s1[i] && i < ft_strlen(s1))
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[j] && j < ft_strlen(s2))
		{
			str[i++] = s2[j++];
		}
		str[i] = '\0';
	}
	return (str);
}
