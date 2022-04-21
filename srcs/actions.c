/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:38:18 by tpereira          #+#    #+#             */
/*   Updated: 2022/04/21 19:07:00 by tpereira         ###   ########.fr       */
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
    if (keycode == 69)
		data->zoom += 5;
	else if (keycode == 78)
		data->zoom -= 5;
    if (keycode == 36)
		data->zoom = 20;
    reset(data);
    return (0);
}

int    move(int keycode, fdf*data)
{
    zoom(keycode, data);
    if (keycode == 65362 || keycode == 126)
		data->shift_y -= 10;
	else if (keycode == 65361 || keycode == 125)
		data->shift_y += 10;
	else if (keycode == 65364 || keycode == 123)
		data->shift_x -= 10;
	else if (keycode == 65363 || keycode == 124)
		data->shift_x += 10;
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