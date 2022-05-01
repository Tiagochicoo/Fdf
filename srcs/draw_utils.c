/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:52:18 by tpereira          #+#    #+#             */
/*   Updated: 2022/04/26 17:26:05 by tpereira         ###   ########.fr       */
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
    map->win_x = 2000;
    map->win_y = 1000;
    map->shift_x = map->win_x / 3;
    map->shift_y = map->win_y / 3;
    map->mlx_ptr = mlx_init();
    map->win_ptr = mlx_new_window(map->mlx_ptr, map->win_x, map->win_y, "FDF");
    image = mlx_new_image(map->mlx_ptr, map->win_x, map->win_y);
    image->addr = mlx_get_map_addr(image, &image->bits_per_pixel, &image->line_length, &image->endian);
    map->img = image;
}

void    reset(fdf*map)
{
    //mlx_clear_window(map->mlx_ptr, map->win_ptr);
    mlx_destroy_image(map->mlx_ptr, map->img);
	map->img = mlx_new_image(map->mlx_ptr, 1000, 500);
	map->img->addr = mlx_get_map_addr(map->img, &map->img->bits_per_pixel, &map->img->line_length, &map->img->endian);
	//blackout(map);
    draw(map);
	print_menu(map);
}