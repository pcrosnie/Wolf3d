/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:48:59 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/23 18:10:56 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*cut;

	i = (size_t)start;
	j = 0;
	cut = (char *)malloc(len + 1);
	if (cut == NULL || !s)
		return (NULL);
	while (j < len && s[i])
	{
		cut[j] = s[i];
		i++;
		j++;
	}
	cut[j] = '\0';
	return (cut);
}
