/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 09:16:22 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/09/03 11:21:05 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw(t_data *ptr, float x, float y)
{
	int nb;

	nb = (x * ptr->bits) / 8 + (y * ptr->len);
	ptr->data_addr[nb] = ptr->red;
	ptr->data_addr[nb + 1] = ptr->green;
	ptr->data_addr[nb + 2] = ptr->blue;
}

void	ft_set_rays(t_data *ptr)
{
	double	rx;
	double	ry;
	double	angle;

	ptr->col = 0;
	angle = ptr->angle - (M_PI / 12);
	rx = cos(angle);
	ry = sin(angle);
	while (angle < ptr->angle + (M_PI / 12))
	{
		rx = cos(angle);
		ry = sin(angle);
		ptr->rx = rx;
		ptr->ry = ry;
		ptr->tmp_angle = angle;
		ft_check_wall(ptr);
		angle += M_PI / 6 / 1280;
		ptr->col++;
	}
}

int		ft_check_pos(t_data *ptr)
{
	if (ptr->map[(int)ptr->posy][(int)ptr->posx] == '1')
		return (0);
	return (1);
}

void	ft_init(t_data *ptr)
{
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, 1280, 800, "wolf");
	ptr->pict = mlx_new_image(ptr->mlx, 1280, 800);
	ptr->data_addr = mlx_get_data_addr(ptr->pict, &(ptr->bits),
			&(ptr->len), &(ptr->endian));
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
	ptr->angle = M_PI_2;
	ptr->red = 255;
	ptr->green = 0;
	ptr->blue = 0;
	ptr->col = 0;
	ptr->posx = 1;
	ptr->posy = 1;
	ft_init(ptr);
}
