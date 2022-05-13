/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:08:41 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/13 22:26:14 by tpereira         ###   ########.fr       */
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

void	isometric(float *x, float *y, float z, fdf*data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - z;
}

void	bresenham(float x, float y, float x1, float y1, fdf*data)
{
	float	x_step;
	float	y_step;
	int		max;
	float	z;
	float	z1;

	//ELEVATION
	z = data->z_matrix[(int)y][(int)x] * data->elevation;
	z1 = data->z_matrix[(int)y1][(int)x1] * data->elevation;
	// ZOOM
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	// COLOR
	if (z > 0 || z1 > 0)
		data->color = 0xFD7F20;
	else if (z < 0 || z1 < 0)
		data->color = 0x0083FF;
	else
		data->color = 0xffffff;
	// ISOMETRIC (3D)
	if (data->iso)
	{
		isometric(&x, &y, z, data);
		isometric(&x1, &y1, z1, data);
	}
	// SHIFT
	x += data->pos_x;
	y += data->pos_y;
	x1 += data->pos_x;
	y1 += data->pos_y;

	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(data->img, x, y, data->color);
		//mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(fdf*data)
{
	int	x;
	int	y;

	blackout(data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 200, 0);
}