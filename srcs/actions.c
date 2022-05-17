/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:38:18 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/17 18:02:55 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	escape(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int	leave(void)
{
	exit(0);
}

int	move(int keycode, t_fdf*data)
{
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

void	actions(t_fdf*data)
{
	while (1)
	{
		mlx_key_hook(data->win_ptr, escape, data);
		mlx_hook(data->win_ptr, 2, 0, move, data);
		mlx_hook(data->win_ptr, 17, 0, leave, data);
		mlx_loop(data->mlx_ptr);
	}
}
