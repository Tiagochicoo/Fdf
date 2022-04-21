/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:52:18 by tpereira          #+#    #+#             */
/*   Updated: 2022/04/21 19:16:04 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    init(fdf*data, img*image)
{
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, 2000, 1000, "FDF");
    image = mlx_new_image(data->mlx_ptr, 1000, 1000);
    image->addr = mlx_get_data_addr(image, &image->bits_per_pixel, &image->line_length, &image->endian);
    data->img = image;
    data->zoom = 20;
    data->angle = 0.8;
}

void    reset(fdf*data)
{
    mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->img->addr = mlx_get_data_addr(data->img, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
	draw(data);
	print_menu(data);
}