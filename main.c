/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 09:16:22 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/09/01 15:21:55 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void    ft_draw(t_data *ptr, float x, float y)
{
	int nb;

	nb = (x * ptr->bits) / 8 + (y * ptr->len);
	ptr->data_addr[nb] = ptr->red;
	ptr->data_addr[nb + 1] = ptr->green;
	ptr->data_addr[nb + 2] = ptr->blue;
}

void	ft_parse_map(char *file, t_data *ptr)
{
	int fd;
	int i;
	char *line;

	fd = open(file, O_RDONLY);
	i = 1;
	line = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	ptr->map = (char **)ft_memalloc(sizeof(char *) * BUFF_SIZE);
	line = ft_memset(line, '\0', BUFF_SIZE);
	while (get_next_line(fd, &line))
	{
		ptr->map[i] = ft_strjoin("1", line);
		ptr->map[i] = ft_strjoin(ptr->map[i], "1");
		i++;
	}
	ptr->map_width = ft_strlen(ptr->map[i - 1]);
	ptr->map[0] = ft_memset(ft_strnew(BUFF_SIZE), '1', ptr->map_width);
	ptr->map[i++] = ft_memset(ft_strnew(BUFF_SIZE), '1', ptr->map_width);
	ptr->map[i] = NULL;
	ptr->map_height = i;

	//	free(line);
}

void    vector_normalize(double *rx, double *ry)
{
	int     mod;

	mod = sqrt((*rx * *rx) + (*ry * *ry));
	*rx /= mod;
	*ry /= mod;
}

void	ft_set_rays(t_data *ptr)
{
	double	rx;
	double	ry;
	double	angle;

	ptr->col = 0;
	angle = ptr->angle - M_PI_4;
	rx = cos(angle);
	ry = sin(angle);
	while (angle < ptr->angle + M_PI_4)
	{
		rx = cos(angle);
		ry = sin(angle);
		ptr->rx = rx;
		ptr->ry = ry;
		ptr->tmp_angle = angle;
		ft_check_wall(ptr);
		angle += M_PI_2 / 1280;
		ptr->col++;
	}
}

int		ft_move(int key, t_data *ptr)
{
	(key == 126) ? ptr->posY += 0.1 : 0;
	(key == 125) ? ptr->posY -= 0.1 : 0;
	(key == 123) ? ptr->posX += 0.1 : 0;
	(key == 124) ? ptr->posX -= 0.1 : 0;
	(key == 0) ? ptr->angle += M_PI_2 / 100 : 0;
	(key == 2) ? ptr->angle -= M_PI_2 / 100 : 0;
	(key == 53) ? exit(0) : 0;
	free(ptr->data_addr);
	ptr->pict = mlx_new_image(ptr->mlx, 1280, 800);
	ptr->data_addr = mlx_get_data_addr(ptr->pict, &(ptr->bits), &(ptr->len), &(ptr->endian));
	ft_set_rays(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->pict, 0, 0);
	return (0);
}

void	ft_init(t_data *ptr)
{
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, 1280, 800, "wolf");
	ptr->pict = mlx_new_image(ptr->mlx, 1280, 800);
	ptr->data_addr = mlx_get_data_addr(ptr->pict, &(ptr->bits) , &(ptr->len), &(ptr->endian));
	ft_set_rays(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->pict, 0, 0);
	mlx_hook(ptr->win, 2, 1l << 0, ft_move, ptr);
	mlx_loop(ptr->mlx);
}

int		main(int argc, char **argv)
{
	t_data *ptr;

	if (argc != 2)
		return (0);
	ptr = (t_data *)malloc(sizeof(t_data));
	ft_parse_map(argv[1], ptr);
	ft_print_char_tab(ptr->map);
	ptr->angle = M_PI_2;
	ptr->red = 255;
	ptr->green = 0;
	ptr->blue = 0;
	ptr->col = 0;
	ptr->posX = 5;
	ptr->posY = 7;
	ft_init(ptr);
}
