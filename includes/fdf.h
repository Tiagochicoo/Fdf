/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:21:52 by tpereira          #+#    #+#             */
/*   Updated: 2022/04/12 19:37:31 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft/includes/libft.h"
#include <mlx.h>
#include <math.h>
typedef struct
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				img;

typedef struct
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	void	*mlx_ptr;
	void	*win_ptr;
	img		*img;
}				fdf;

void	read_file(char *filename, fdf *data);
void	bresenham(float x, float y, float x1, float y1, fdf*data, img*img);
void	draw(fdf*data, img*img);

#endif