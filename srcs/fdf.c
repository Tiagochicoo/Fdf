/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:27:30 by tpereira          #+#    #+#             */
/*   Updated: 2021/09/17 18:25:46 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <mlx.h>

int	dela_key(int key, void *data)
{
	ft_printf("%d", key);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	ii;
	fdf *data;

	i = 0;
	data = (fdf*)malloc(sizeof(fdf));
	read_file(argv[1], data);
	while (i < data->height)
	{
		ii = 0;
		while (ii < data->width)
		{
			printf("%d ", data->z_matrix[i][ii]);
			ii++;
		}
		printf("\n");
		i++;
	}
}