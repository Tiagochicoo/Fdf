/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:08:41 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/17 21:19:52 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x < data->win_x && y < data->win_y && x > 0 && y > 0)
	{
		dst = data->img.addr + (y * data->img.line_length + x
				* (data->img.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

float	max_num(float a, float b)
{
	if (a < b)
		return (b);
	return (a);
}

float	module(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	isometric(float *x, float *y, float z, t_fdf*data)
{
	*x = (*x - *y) * cos(data->angle_x);
	*y = (*x + *y) * sin(data->angle_y) - z;
}

int	set_color(t_info info)
{
	if (info.z > 0 || info.z1 > 0)
		return (0xFD7F20);
	else if (info.z < 0 || info.z1 < 0)
		return (0x0083FF);
	else
		return (0xffffff);
}

void	set_iso(t_info *info, t_fdf *data)
{
	if (data->iso)
	{
		isometric(&info->x, &info->y, info->z, data);
		isometric(&info->x1, &info->y1, info->z1, data);
	}
}

void	set_pos(t_info *info, t_fdf *data)
{
	info->x += data->pos_x;
	info->y += data->pos_y;
	info->x1 += data->pos_x;
	info->y1 += data->pos_y;
}

void	set_step(t_info *info)
{
	info->x_step = info->x1 - info->x;
	info->y_step = info->y1 - info->y;
	info->max = max_num(module(info->x_step), module(info->y_step));
	info->x_step /= info->max;
	info->y_step /= info->max;
}

void	bresenham(int coord[], float x1, float y1, t_fdf*data)
{
	t_info	info;

	info.x = coord[0];
	info.y = coord[1];
	info.z = data->z_matrix[(int)info.y][(int)info.x] * data->elevation;
	info.z1 = data->z_matrix[(int)y1][(int)x1] * data->elevation;
	info.x *= data->zoom;
	info.y *= data->zoom;
	info.x1 = x1 * data->zoom;
	info.y1 = y1 * data->zoom;

	data->color = set_color(info);
	set_iso(&info, data);
	set_pos(&info, data);
	set_step(&info);
	while ((int)(info.x - info.x1) || (int)(info.y - info.y1))
	{
		my_mlx_pixel_put(data, info.x, info.y + 1, data->color);
		info.x += info.x_step;
		info.y += info.y_step;
	}
}

void	draw(t_fdf*data)
{
	int	x;
	int	y;
	int	coord[2];

	blackout(data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			coord[1] = y;
			coord[0] = x;
			if (y < data->height - 1)
				bresenham(coord, x, y + 1, data);
			if (x < data->width - 1)
				bresenham(coord, x + 1, y, data);
			else
				break ;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
}
