/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:21:52 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/17 20:39:40 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_opengl/mlx.h"
# include "../libft/includes/libft.h"
# include <math.h>

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fdf
{
	int				width;
	int				height;
	int				**z_matrix;
	int				zoom;
	double			angle_x;
	double			angle_y;
	int				iso;
	int				elevation;
	int				color;
	int				pos_x;
	int				pos_y;
	int				win_x;
	int				win_y;
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
}				t_fdf;

typedef struct s_info
{
	float	x;
	float	y;
	float	z;
	float	x1;
	float	y1;
	float	z1;
	int		max;
	float	x_step;
	float	y_step;		
}				t_info;

void	read_file(char *filename, t_fdf *data);
void	bresenham(int coord[], float x1, float y1, t_fdf*data);
void	draw(t_fdf*data);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
void	actions(t_fdf*data);
void	reset(t_fdf*data);
int		revert(int keycode, t_fdf*data);
int		zoom(int keycode, t_fdf*data);
int		rotate(int keycode, t_fdf*data);
int		elevation(int keycode, t_fdf*data);
void	init(t_fdf*data);
void	start(t_fdf*data);
void	print_menu(t_fdf*data);
void	blackout(t_fdf*data);

#endif