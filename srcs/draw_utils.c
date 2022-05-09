/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:52:18 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/05 18:02:16 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    blackout(fdf*data)
{
    int	x;
	int	y;

	y = 0;
	while (y < 1000)
	{
		x = 0;
		while (x < 2000)
		{
			my_mlx_pixel_put(data->img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void    init(fdf*data, img*image)
{
	int	width;
	int	height;

	width = (data->width / data->height) * 1500;
	height = (data->width / data->height) * 1000;
    data->zoom = (width / height) * 10;
    //data->angle = 0.523599;
    data->angle = 0.8165;
    data->elevation = 1;
	data->pos_x = width / 2;
	data->pos_y = height / 4;
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "FDF");
    image = mlx_new_image(data->mlx_ptr, data->width, data->height);
    image->addr = mlx_get_data_addr(image, &image->bits_per_pixel, &image->line_length, &image->endian);
    data->img = image;
}

void    reset(fdf*data)
{
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    //mlx_destroy_image(data->mlx_ptr, data->img);
	//data->img = mlx_new_image(data->mlx_ptr, 1000, 1000);
	//data->img->addr = mlx_get_data_addr(data->img, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
	draw(data);
	print_menu(data);
}