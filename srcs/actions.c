/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:38:18 by tpereira          #+#    #+#             */
/*   Updated: 2022/04/22 16:54:57 by tpereira         ###   ########.fr       */
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

int    zoom(int keycode, fdf*map)
{
	if (keycode == 69)
		map->zoom += 5;
	else if (keycode == 78)
		map->zoom -= 5;
	if (keycode == 36)
		map->zoom = 20;
	reset(map);
		return (0);
}

int    move(int keycode, fdf*map)
{
	zoom(keycode, map);
	if (keycode == 65362 || keycode == 126)
		map->shift_y -= 10;
	else if (keycode == 65361 || keycode == 125)
		map->shift_y += 10;
	else if (keycode == 65364 || keycode == 123)
		map->shift_x -= 10;
	else if (keycode == 65363 || keycode == 124)
		map->shift_x += 10;
	reset(map);
		return (0);
}

// int	click(int keycode, fdf*map)
// {
// 	printf("key ->%d\n", keycode);
// 	if (keycode == 1)
// 		printf("zoom: %d", map->zoom);
// 	//reset(map);
// 	return (0);
// }

void    actions(fdf*map)
{
	while (1)
	{
		mlx_key_hook(map->win_ptr, escape, map);
		mlx_hook(map->win_ptr, 02, 0, move, map); // 04 keys+buttons | 02 only keyboard
		//mlx_mouse_hook(map->win_ptr, click, map);
		mlx_do_key_autorepeaton(map->mlx_ptr);
		mlx_hook(map->win_ptr, 17, 0, leave, map);
		mlx_loop(map->mlx_ptr);
	}
}