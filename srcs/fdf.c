/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:27:30 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/17 18:53:09 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_menu(t_fdf*data)
{
	char	*menu;

	menu = "How to use:";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 25, 0xffffff, menu);
	menu = "up, down, left, right: move picture";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 45, 0xffffff, menu);
	menu = "+, -: zoom";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 65, 0xffffff, menu);
	menu = "5: toggle projection";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 85, 0xffffff, menu);
	menu = "4: x axis angle";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 105, 0xffffff, menu);
	menu = "6: y axis angle";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 125, 0xffffff, menu);
	menu = "2, 8: elevation";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 145, 0xffffff, menu);
	menu = "backspace: reset";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 165, 0xffffff, menu);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf map.fdf\n");
		exit(1);
	}
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(ft_strdup(argv[1]), data);
	init(data);
	draw(data);
	print_menu(data);
	actions(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
