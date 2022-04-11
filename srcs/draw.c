/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:08:41 by tpereira          #+#    #+#             */
/*   Updated: 2022/04/11 18:29:32 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define MAX(a, b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

float	mod(float i)
{
	return (i< 0) ? -i : i;
}

void	bresenham(float x, float y, float x1, float y1, fdf*data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	
	data->color = (z) > 0 ? 0xe80c0c : 0xffffff;
	
	x_step = x1 - x;
	y_step = y1 - y;	
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y,  data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(fdf*data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height - 1)
	{
		x = 0;
		while (x < data->width - 1)
		{
			bresenham(x, y, x + 1, y, data);
			bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
	
}