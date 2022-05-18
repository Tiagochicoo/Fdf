/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:42:11 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/18 20:46:17 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

int	set_color(t_info info)
{
	if (info.z > 0 || info.z1 > 0)
		return (0xFD7F20);
	else if (info.z < 0 || info.z1 < 0)
		return (0x0083FF);
	else
		return (0xffffff);
}

void	set_step(t_info *info)
{
	info->x_step = info->x1 - info->x;
	info->y_step = info->y1 - info->y;
	info->max = max_num(module(info->x_step), module(info->y_step));
	info->x_step /= info->max;
	info->y_step /= info->max;
}

void	isometric(float *x, float *y, float z, t_fdf*data)
{
	*x = (*x - *y) * cos(data->angle_x);
	*y = (*x + *y) * sin(data->angle_y) - z;
}
