/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 10:25:23 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/09/03 12:29:15 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_check_up_down(int key, t_data *ptr)
{
	if (key == 126)
	{
		ptr->posy += 0.2 * sin(ptr->angle);
		ptr->posx += 0.2 * cos(ptr->angle);
		if (ft_check_pos(ptr) == 0)
		{
			ptr->posy -= 0.2 * sin(ptr->angle);
			ptr->posx -= 0.2 * cos(ptr->angle);
		}
	}
	if (key == 125)
	{
		ptr->posy -= 0.2 * sin(ptr->angle);
		ptr->posx -= 0.2 * cos(ptr->angle);
		if (ft_check_pos(ptr) == 0)
		{
			ptr->posy += 0.2 * sin(ptr->angle);
			ptr->posx += 0.2 * cos(ptr->angle);
		}
	}
}

void	ft_check_right_left(int key, t_data *ptr)
{
	if (key == 123)
	{
		ptr->posy -= 0.2 * cos(ptr->angle);
		ptr->posx += 0.2 * sin(ptr->angle);
		if (ft_check_pos(ptr) == 0)
		{
			ptr->posy += 0.2 * cos(ptr->angle);
			ptr->posx -= 0.2 * sin(ptr->angle);
		}
	}
	if (key == 124)
	{
		ptr->posy += 0.2 * cos(ptr->angle);
		ptr->posx -= 0.2 * sin(ptr->angle);
		if (ft_check_pos(ptr) == 0)
		{
			ptr->posy -= 0.2 * cos(ptr->angle);
			ptr->posx += 0.2 * sin(ptr->angle);
		}
	}
}

int		ft_move(int key, t_data *ptr)
{
	ft_check_up_down(key, ptr);
	ft_check_right_left(key, ptr);
	(key == 0) ? ptr->angle -= M_PI_2 / 25 : 0;
	(key == 2) ? ptr->angle += M_PI_2 / 25 : 0;
	(key == 53) ? exit(0) : 0;
	free(ptr->data_addr);
	ptr->pict = mlx_new_image(ptr->mlx, 1280, 800);
	ptr->data_addr = mlx_get_data_addr(ptr->pict, &(ptr->bits),
			&(ptr->len), &(ptr->endian));
	ft_set_rays(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->pict, 0, 0);
	return (0);
}
