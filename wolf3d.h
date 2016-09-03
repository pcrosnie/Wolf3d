/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 09:16:46 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/09/03 09:59:18 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx.h"
# include <stdio.h>

typedef struct	s_data
{
	void *mlx;
	void *win;
	char *data_addr;
	void *pict;
	int	 bits;
	int  len;
	int	 endian;
	char **map;
	int		map_height;
	int		map_width;
	double posX;
	double posY;
	double angle;
	double tmp_angle;
	double rx;
	double ry;
	int red;
	int green;
	int blue;
	int incl;
	int color;
	int col;
	int tmp_len;
}				t_data;

void	ft_check_wall(t_data *ptr);
void	ft_draw(t_data *ptr, float x, float y);

#endif
