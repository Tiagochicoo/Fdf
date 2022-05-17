/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:27:16 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/17 18:29:49 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	zoom(int keycode, t_fdf*data)
{
	if (data->zoom > 0)
	{
		if (keycode == 78 || keycode == 27)
			data->zoom -= 1;
	}
	if (data->zoom < 500)
	{
		if (keycode == 69 || keycode == 24)
			data->zoom += 1;
	}
	if (keycode == 87 || keycode == 18)
	{
		if (data->iso)
		{
			data->iso = 0;
			data->pos_x -= 250;
		}
		else
		{
			data->iso = 1;
			data->pos_x += 250;
		}
	}
	reset(data);
	return (0);
}

int	rotate(int keycode, t_fdf*data)
{
	if (keycode == 88)
		data->angle_x += 0.05;
	else if (keycode == 86)
		data->angle_y += 0.05;
	return (0);
}

int	elevation(int keycode, t_fdf*data)
{
	if (keycode == 84 || keycode == 5)
		data->elevation -= 1;
	else if (keycode == 91 || keycode == 17)
		data->elevation += 1;
	return (0);
}
