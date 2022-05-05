/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:52:18 by tpereira          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/02 19:28:55 by tpereira         ###   ########.fr       */
=======
/*   Updated: 2022/05/05 18:02:16 by tpereira         ###   ########.fr       */
>>>>>>> new
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    blackout(fdf*map)
{
    int	x;
	int	y;

	y = 0;
	while (y < 1000)
	{
		x = 0;
		while (x < 2000)
		{
			my_mlx_pixel_put(map->img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void    init(fdf*map, img*image)
{
    map->zoom = 20;
    map->z_height = 1;
    map->angle = 0.8;
    map->mlx_ptr = mlx_init();
    map->win_ptr = mlx_new_window(map->mlx_ptr, 2000, 1000, "FDF");
    image = mlx_new_image(map->mlx_ptr, 2000, 1000);
    image->addr = mlx_get_data_addr(image, &image->bits_per_pixel, &image->line_length, &image->endian);
    map->img = image;
}

void    reset(fdf*map)
{
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    //mlx_destroy_image(data->mlx_ptr, data->img);
	//data->img = mlx_new_image(data->mlx_ptr, 1000, 1000);
	//data->img->addr = mlx_get_data_addr(data->img, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
	draw(data);
	print_menu(data);
}