/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 11:29:24 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/09/01 18:20:07 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_set_wall_color(t_data *ptr, double x, double y, double i)
{
	double tmpX;
	double tmpY;
	double tmp;
	
	tmpX = ptr->posX + (ptr->rx * i);
	tmpY = ptr->posY + (ptr->ry * i);
	x += 0.5;
	tmp = hypot(x - tmpX, y - tmpY);
	ptr->color = 1;
	x -= 0.5;
	y += 0.5;
	if (hypot(x - tmpX, y - tmpY) < tmp)
	{
		tmp = hypot(x - tmpX, y - tmpY);
		ptr->color = 2;
	}
	x += 1;
	if (hypot(x - tmpX, y - tmpY) < tmp)
	{
		tmp = hypot(x - tmpX, y - tmpY);
		ptr->color = 3;
	}
	x -= 0.5;
	y += 0.5;
	if (hypot(x - tmpX, y - tmpY) < tmp)
	{
		ptr->color = 4;
	}
	x -= 0.5;
	y -= 1;/*
	(hypot(x - tmpX, y - tmpY) < 0.02 * (hypot(ptr->posX - x, ptr->posY - y) * 0.1)) ? ptr->color = 0 : 0;
	(hypot(x + 1 - tmpX, y - tmpY) < 0.02 * (hypot(ptr->posX - x + 1, ptr->posY - y) * 0.1)) ? ptr->color = 0 : 0;
	(hypot(x - tmpX, y + 1 - tmpY) < 0.02 * (hypot(ptr->posX - x, ptr->posY - y + 1) * 0.1)) ? ptr->color = 0 : 0;
	(hypot(x + 1 - tmpX, y + 1 - tmpY) < 0.02 * (hypot(ptr->posX - x + 1, ptr->posY - y + 1) * 0.1)) ? ptr->color = 0 : 0;
*/	
	(hypot(x - tmpX, y - tmpY) < 0.02) ? ptr->color = 0 : 0;
	(hypot(x + 1 - tmpX, y - tmpY) < 0.02) ? ptr->color = 0 : 0;
	(hypot(x - tmpX, y + 1 - tmpY) < 0.02) ? ptr->color = 0 : 0;
	(hypot(x + 1 - tmpX, y + 1 - tmpY) < 0.02) ? ptr->color = 0 : 0;

}

int		ft_inter(t_data *ptr, double i)
{
	double tmpX;
	double tmpY;
	int x;
	int y;

	tmpX = ptr->posX + (ptr->rx * i);
	x = (int)tmpX;
	tmpY = ptr->posY + (ptr->ry * i);
	y = (int)tmpY;
	ft_set_wall_color(ptr, x, y, i);
	if (ptr->map[y] && ptr->map[y][x] && ptr->map[y][x] == '1')
		return (1);
	return (0);
}

void	ft_set_color(t_data *ptr)
{
	if (ptr->color == 0)
	{
		ptr->red = 0;
		ptr->green = 0;
		ptr->blue = 0;
	}
	if (ptr->color == 1)
	{
		ptr->red = 0;
		ptr->green = 255;
		ptr->blue = 0;
	}
	if (ptr->color == 2)
	{
		ptr->red = 255;
		ptr->blue = 255;
		ptr->green = 0;
	}
	if (ptr->color == 3)
	{
		ptr->red = 255;
		ptr->green = 255;
		ptr->blue = 0;
	}
	if (ptr->color == 4)
	{
		ptr->red = 255;
		ptr->blue = 0;
		ptr->green = 0;
	}
}

void	ft_draw_ray(t_data *ptr, double a)
{
	int i;
	int height;

	a = a * cos(ptr->tmp_angle - ptr->angle);
//	printf("\n%f\n", a);
	height = 1200 / a;
	i = 400 - height;
	(i < 0) ? i = 0 : 0;
	ft_set_color(ptr);
//	ptr->blue = 0;
//	ptr->red = 255;
	while (i < 400 + height && i < 800 && i >= 0 && ptr->col < 1280)
		ft_draw(ptr, ptr->col, i++);
	ptr->red = 0;
	ptr->blue = 0;
	ptr->green = 0;
	while (i < 400 + height + 4 && i < 800)
	ft_draw(ptr, ptr->col, i++);
	ptr->red = 0;
	ptr->blue = 255;
	ptr->green = 0;
	while (i < 799 && i > 0 && ptr->col < 1280)
		ft_draw(ptr, ptr->col, i++);
}

void	ft_check_wall(t_data *ptr)
{
	double	i;
	int a;
	int color;

	i = 0;
	a = 0;
	color = 0;
	while (ptr->posX + (ptr->rx * i) < ptr->map_width && ptr->posY + (ptr->ry * i) < ptr->map_height && a == 0
	 && ptr->posX + (ptr->rx * i) >= 0 && ptr->posY + (ptr->ry * i) >= 0 && a == 0)
	{
		if (ft_inter(ptr, i) == 1)
		{
		//	i -= 1;
		//	while (ft_inter(ptr, i) != 1)
		//		i += 0.1;
			i -= 0.1;
			while (ft_inter(ptr, i) != 1)
				i += 0.001;
//			ft_set_colors(ptr);
			a = 1;
			ft_draw_ray(ptr, i);
		}
		i += 0.1;
	}
}
