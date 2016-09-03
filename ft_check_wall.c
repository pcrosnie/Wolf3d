/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 11:29:24 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/09/03 12:14:24 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_inter(t_data *ptr, double i)
{
	double	tmpx;
	double	tmpy;
	int		x;
	int		y;

	ptr->color = 1;
	tmpx = ptr->posx + (ptr->rx * i);
	x = (int)tmpx;
	tmpy = ptr->posy + (ptr->ry * i);
	y = (int)tmpy;
	ft_set_wall_color(ptr, x, y, i);
	if (ptr->map[y] && ptr->map[y][x] && ptr->map[y][x] == '1')
		return (1);
	return (0);
}

void	ft_set_shadow(t_data *ptr, double a)
{
	a *= 3;
	if (ptr->red - a < 0)
		ptr->red = 0;
	else
		ptr->red -= a;
	if (ptr->blue - a < 0)
		ptr->blue = 0;
	else
		ptr->blue -= a;
	if (ptr->green - a < 0)
		ptr->green = 0;
	else
		ptr->green -= a;
}

void	ft_draw_ray(t_data *ptr, double a)
{
	int i;
	int height;

	a = a * cos(ptr->tmp_angle - ptr->angle);
	height = 1200 / a;
	i = 400 - height;
	(i < 0) ? i = 0 : 0;
	ft_set_color(ptr);
	(ptr->shadow == 1) ? ft_set_shadow(ptr, a) : 0;
	while (i < 400 + height && i < 800 && i >= 0 && ptr->col < 1280)
		ft_draw(ptr, ptr->col, i++);
	ptr->red = 0;
	ptr->blue = 0;
	ptr->green = 0;
	while (i < 400 + height + 4 && i < 800)
		ft_draw(ptr, ptr->col, i++);
	ptr->red = 0;
	ptr->blue = 50;
	ptr->green = 0;
	while (i < 799 && i > 0 && ptr->col < 1280)
	{
		ft_draw(ptr, ptr->col, i++);
		(i % 3 == 0) ? ptr->blue++ : 0;
	}
}

void	ft_check_wall(t_data *ptr)
{
	double	i;
	int		a;
	int		color;

	i = 0;
	a = 0;
	color = 0;
	while (ptr->posx + (ptr->rx * i) < ptr->map_width && ptr->posy +
		(ptr->ry * i) < ptr->map_height && a == 0 && ptr->posx + (ptr->rx
			* i) >= 0 && ptr->posy + (ptr->ry * i) >= 0 && a == 0)
	{
		if (ft_inter(ptr, i) == 1)
		{
			i -= 0.1;
			while (ft_inter(ptr, i) != 1)
				i += 0.001;
			a = 1;
			ft_draw_ray(ptr, i);
		}
		i += 0.1;
	}
}
