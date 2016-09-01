/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 11:29:24 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/09/01 15:24:34 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_inter(t_data *ptr, double i)
{
	double tmp;
	int x;
	int y;

	tmp = ptr->posX + (ptr->rx * i);
	x = (int)tmp;
	tmp = ptr->posY + (ptr->ry * i);
	y = (int)tmp;
	if (ptr->map[y] && ptr->map[y][x] && ptr->map[y][x] == '1')
		return (1);
	return (0);
}

void	ft_draw_ray(t_data *ptr, float a)
{
	int i;
	int height;

	a = a * cos(ptr->tmp_angle - ptr->angle);
//	printf("\n%f\n", a);
	height = 400 / a;
	i = 400 - height;
	ptr->blue = 0;
	ptr->red = 255;
	while (i < 400 + height && i < 800 && i > 0)
		ft_draw(ptr, ptr->col, i++);
	ptr->red = 0;
	ptr->blue = 255;
	while (i < 799 && i > 0)
		ft_draw(ptr, ptr->col, i++);
}

void	ft_check_wall(t_data *ptr)
{
	double	i;
	int a;

	i = 0;
	a = 0;
	while (ptr->posX + (ptr->rx * i) < ptr->map_width && ptr->posY + (ptr->ry * i) < ptr->map_height && a == 0
	 && ptr->posX + (ptr->rx * i) >= 0 && ptr->posY + (ptr->ry * i) >= 0 && a == 0)
	{
		if (ft_inter(ptr, i) == 1)
		{
			a = 1;
			ft_draw_ray(ptr, i);
		}
		i += 0.01;
	}
}
