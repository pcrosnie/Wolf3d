/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 10:35:19 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/09/03 12:11:33 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_check_edge(double tmpx, double tmpy, double x, double y)
{
	int a;

	a = 0;
	(hypot(x - tmpx, y - tmpy) < 0.02) ? a++ : 0;
	(hypot(x + 1 - tmpx, y - tmpy) < 0.02) ? a++ : 0;
	(hypot(x - tmpx, y + 1 - tmpy) < 0.02) ? a++ : 0;
	(hypot(x + 1 - tmpx, y + 1 - tmpy) < 0.02) ? a++ : 0;
	if (a != 0)
		return (1);
	return (0);
}

void	ft_set_wall_color(t_data *ptr, double x, double y, double i)
{
	double tmpx;
	double tmpy;
	double tmp;

	tmpx = ptr->posx + (ptr->rx * i);
	tmpy = ptr->posy + (ptr->ry * i);
	x += 0.5;
	tmp = hypot(x - tmpx, y - tmpy);
	x -= 0.5;
	y += 0.5;
	if (hypot(x - tmpx, y - tmpy) < tmp)
	{
		tmp = hypot(x - tmpx, y - tmpy);
		ptr->color = 2;
	}
	x += 1;
	if (hypot(x - tmpx, y - tmpy) < tmp)
	{
		tmp = hypot(x - tmpx, y - tmpy);
		ptr->color = 3;
	}
	x -= 0.5;
	y += 0.5;
	(hypot(x - tmpx, y - tmpy) < tmp) ? ptr->color = 4 : 0;
	(ft_check_edge(tmpx, tmpy, x - 0.5, y - 1) == 1) ? ptr->color = 0 : 0;
}

void	ft_set_f_colors(t_data *ptr)
{
	if (ptr->color == 0)
	{
		ptr->red = 0;
		ptr->green = 0;
		ptr->blue = 0;
	}
	if (ptr->color == 1)
	{
		ptr->red = 90;
		ptr->green = 170;
		ptr->blue = 0;
	}
}

void	ft_set_color(t_data *ptr)
{
	ft_set_f_colors(ptr);
	if (ptr->color == 2)
	{
		ptr->red = 0;
		ptr->blue = 200;
		ptr->green = 145;
	}
	if (ptr->color == 3)
	{
		ptr->red = 150;
		ptr->green = 0;
		ptr->blue = 0;
	}
	if (ptr->color == 4)
	{
		ptr->red = 145;
		ptr->blue = 145;
		ptr->green = 0;
	}
}
