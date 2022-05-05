/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:21:52 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/05 18:50:24 by tpereira         ###   ########.fr       */
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
	int				width;
	int				height;
	int				**z_matrix;
	unsigned int	zoom;
	double			angle;
	int				color;
	int				iso;
	int				shift_x;
	int				shift_y;
	void			*mlx_ptr;
	void			*win_ptr;
	img				*img;
}				fdf;

void	read_file(char *filename, fdf *data);
void	bresenham(float x, float y, float x1, float y1, fdf*data);
void	draw(fdf*data);
void	my_mlx_pixel_put(img *img, int x, int y, int color);
void    actions(fdf*data);
void    reset(fdf*data);
void    init(fdf*data, img*image);
void	print_menu(fdf*data);

#endif