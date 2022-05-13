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

void    blackout(fdf*data)
{
    int	x;
	int	y;

	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 1000)
		{
			my_mlx_pixel_put(data->img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void    init(fdf*data)
{
	int	width;
	int	height;
	int	zoom;
	
	width = 1000;
	height = 800;
	zoom = (width / data->width);
	if (zoom > height / data->height)
		zoom = (height / data->height);
	data->zoom = zoom * 0.7;
    //data->angle = 0.523599;
	data->angle = 0.8165;
	data->pos_x = width / 2;
	data->pos_y = height / 6;
	data->elevation = 1;
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "FDF");
    data->img = mlx_new_image(data->mlx_ptr, width, height);
    data->img->addr = mlx_get_data_addr(data->img, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
}

void    reset(fdf*data)
{
    //mlx_clear_window(data->mlx_ptr, data->win_ptr);
    //mlx_destroy_image(data->mlx_ptr, data->img);
	//data->img = mlx_new_image(data->mlx_ptr, 1000, 800);
	//data->img->addr = mlx_get_data_addr(data->img, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
	draw(data);
	print_menu(data);
}