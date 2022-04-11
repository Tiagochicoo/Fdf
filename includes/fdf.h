/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:21:52 by tpereira          #+#    #+#             */
/*   Updated: 2022/04/11 18:40:03 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft/includes/libft.h"
#include <mlx.h>
#include <math.h>

typedef struct 
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;

	void	*mlx_ptr;
	void	*win_ptr;
}				fdf;

void	read_file(char *filename, fdf *data);
void	bresenham(float x, float y, float x1, float y1, fdf*data);
void	draw(fdf*data);

#endif