/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:38:18 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/05 18:01:32 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int    escape(int keycode)
{
		if (keycode == 53)
		exit(0);
		return (0);
}

int    leave(void)
{
	exit(0);
}

int    zoom(int keycode, fdf*data)
{
	if (data->zoom > 0)
	{
		if (keycode == 78 || keycode == 27)
			data->zoom -= 5;
	}
	if (keycode == 69 || keycode == 24)
		data->zoom += 5;
	if (keycode == 87 || keycode == 18)
	{
		if (data->iso)
			data->iso = 0;
		else
			data->iso = 1;
	}
	reset(data);
	return (0);
}

int	rotate(int keycode, fdf*data)
{
	if (keycode == 88)
		data->angle += 0.05;
	else if (keycode == 86)
		data->angle -= 0.05;
	return (0);
}

int	elevation(int keycode, fdf*data)
{
	if (keycode == 84 || keycode == 5)
		data->elevation -= 1;
	else if (keycode == 91 || keycode == 17)
		data->elevation += 1;
	return (0);
}

int	revert(int keycode, fdf*data)
{
	int	width;
	int	height;

	if (keycode == 51)
		{
			width = (data->width / data->height) * 1000;
			height = (data->width / data->height) * 1000;
			data->zoom = (width / height) * 20;
			data->angle = 0.8165;
			data->pos_x = width / 2;
			data->pos_y = height / 2;
			data->elevation = 1;
		}
	return (0);
}

int    move(int keycode, fdf*data)
{
	printf("keycode -> %d\n", keycode);
    zoom(keycode, data);
	rotate(keycode, data);
	elevation(keycode, data);
	revert(keycode, data);
    if (keycode == 65362 || keycode == 126)
		data->pos_y -= 10;
	else if (keycode == 65361 || keycode == 125)
		data->pos_y += 10;
	else if (keycode == 65364 || keycode == 123)
		data->pos_x -= 10;
	else if (keycode == 65363 || keycode == 124)
		data->pos_x += 10;
	reset(data);
		return (0);
}

void    actions(fdf*data)
{
		while (1)
		{
			mlx_key_hook(data->win_ptr, escape, data);
			mlx_hook(data->win_ptr, 02, 0, move, data); // 04 keys+buttons | 02 only keyboard
			mlx_hook(data->win_ptr, 17, 0, leave, data);
			mlx_loop(data->mlx_ptr);
		}
}