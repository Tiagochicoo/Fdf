/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:52:18 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/13 18:39:37 by tpereira         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	clean(t_fdf*data)
{
	free(data);
}

void	blackout(t_fdf*data)
{
	int	x;
	int	y;

	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 1000)
		{
			my_mlx_pixel_put(data, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

int	revert(int keycode, t_fdf*data)
{
	if (keycode == 51)
	{
		data->win_x = 1000;
		data->win_y = 800;
		data->zoom = (data->win_x / data->width);
		if (data->zoom > data->win_y / data->height)
			data->zoom = (data->win_y / data->height);
		data->zoom = data->zoom * 0.7;
		data->angle_x = 0.523599;
		data->angle_y = 0.523599;
		data->pos_x = data->win_x / 2;
		data->pos_y = data->win_y / 6;
		data->elevation = 1;
	}
	return (0);
}

void	init(t_fdf*data)
{
	data->win_x = 1000;
	data->win_y = 800;
	data->zoom = (data->win_x / data->width);
	if (data->zoom > data->win_y / data->height)
		data->zoom = (data->win_y / data->height);
	data->zoom = data->zoom * 0.7;
	data->angle_x = 0.523599;
	data->angle_y = 0.523599;
	data->pos_x = (data->win_x / 2) - 100;
	data->pos_y = data->win_y / 6;
	data->elevation = 1;
	data->iso = 1;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_x,
			data->win_y, "FDF");
	data->img.ptr = mlx_new_image(data->mlx_ptr, data->win_x, data->win_y);
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bpp,
			&data->img.line_length, &data->img.endian);
}

void	reset(t_fdf*data)
{
	draw(data);
	print_menu(data);
}
