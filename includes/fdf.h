/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:21:52 by tpereira          #+#    #+#             */
/*   Updated: 2022/04/08 18:28:40 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft/includes/libft.h"
#include <mlx.h>

typedef struct 
{
	int	width;
	int	height;
	int	**z_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}				fdf;

void	read_file(char *filename, fdf *data);
void	bresenham(float x, float y, float x1, float y1, fdf*data);


#endif