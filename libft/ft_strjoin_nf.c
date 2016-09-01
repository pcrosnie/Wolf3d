/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_nf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 13:31:08 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/11 13:33:31 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin_nf(char *s1, char *s2, int nb)
{
	char    *str;
	size_t  i;
	size_t  j;

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
		while (s2[j])
			str[i++] = s2[j++];
		str[i] = '\0';
	}
	(nb == 1) ? free(s1) : 0;
	(nb == 2) ? free(s2) : 0;
	if (nb == 3)
	{
		free(s1);
		free(s2);
	}
	return (str);
}
