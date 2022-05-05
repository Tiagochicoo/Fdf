/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:08:41 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/05 18:36:52 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define MAX(a, b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

void	my_mlx_pixel_put(img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

float	mod(float i)
{
	return (i < 0) ? -i : i;
}

void	isometric(float *x, float *y, float z, fdf*map)
{
	*x = (*x - *y) * cos(map->angle);
	*y = (*x + *y) * sin(map->angle) - z;
}

void	bresenham(float x, float y, float x1, float y1, fdf*map)
{
	float	x_step;
	float	y_step;
	int		max;
	float	z;
	float	z1;

	z = map->z_matrix[(int)y][(int)x];
	z1 = map->z_matrix[(int)y1][(int)x1];
	// ZOOM
	x *= map->zoom;
	y *= map->zoom;
	x1 *= map->zoom;
	y1 *= map->zoom;
	// COLOR
	map->color = (z || z1) > 0 ? 0xe80c0c : 0xffffff;
	// ISOMETRIC (3D)
	isometric(&x, &y, z, map);
	isometric(&x1, &y1, z1, map);
	// SHIFT
	x += map->shift_x;
	y += map->shift_y;
	x1 += map->shift_x;
	y1 += map->shift_y;

	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 100, 100);
}

void	draw(fdf*map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->win_y)
	{
		x = 0;
		while (x < map->win_x)
		{
			if (x < map->win_x - 1)
				bresenham(x, y, x + 1, y, map);
			if (y < map->win_y - 1)
				bresenham(x, y, x, y + 1, map);
			if (x >= map->win_x || y >= map->win_y)
			 	break ;
			x++;
		}
		y++;
	}
	
}