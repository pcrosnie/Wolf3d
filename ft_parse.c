/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 10:20:22 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/09/03 11:42:59 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_check_line(char *line, int j, int len)
{
	int i;

	i = 0;
	if (!line || !line[0])
		return (0);
	while (line && line[i])
	{
		if (line[i] != '1' && line[i] != '0')
			return (0);
		if (len != (int)ft_strlen(line) && j != 1)
			return (0);
		i++;
	}
	return (1);
}

void	ft_parse_map(char *file, t_data *ptr)
{
	int		fd;
	int		i;
	char	*line;
	int		ret;

	fd = open(file, O_RDONLY);
	i = 1;
	line = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	ptr->map = (char **)ft_memalloc(sizeof(char *) * BUFF_SIZE);
	line = ft_memset(line, '\0', BUFF_SIZE);
	while ((ret = get_next_line(fd, &line)))
	{
		(ft_check_line(line, i, ptr->tmp_len) == 0) ? exit(0) : 0;
		ptr->map[i] = ft_strjoin("1", line);
		ptr->map[i] = ft_strjoin(ptr->map[i], "1");
		ptr->tmp_len = ft_strlen(line);
		i++;
	}
	((ret <= 0 || fd < 0) && i == 1) ? exit(0) : 0;
	ptr->map_width = ft_strlen(ptr->map[i - 1]);
	ptr->map[0] = ft_memset(ft_strnew(BUFF_SIZE), '1', ptr->map_width);
	ptr->map[i++] = ft_memset(ft_strnew(BUFF_SIZE), '1', ptr->map_width);
	ptr->map[i] = NULL;
	ptr->map_height = i;
	free(line);
}
