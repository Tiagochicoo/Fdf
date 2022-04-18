/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:27:30 by tpereira          #+#    #+#             */
/*   Updated: 2022/04/18 18:07:28 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** --------------------- Resources-----------------------------
** --------------- 3D ------------------------------------------
**  x` = (x - y) * cos(angle);
**  y` = (x + y) * sin(angle) - z;
** -------------------------------------------------------------
**  ------- mlx_function ----------------------------------------
**  void *mlx_ptr;
**  void *win_ptr;
**
**  mlx_ptr = mlx_init();
**  win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "FDF");
**
**  mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, #color);
**
**  mlx_key_hook(win_ptr, deal_key, NULL);
**  mlx_loop(mlx_ptr);
** --------------------------------------------------------------
** ------- deal_key prototype -----------------------------------
**  int  deal_key(int key, void *data);
** --------------------------------------------------------------
** colors:
**  white = 0xffffff
**  red = 0xe80c0c
** ----------------------------
** frameworks:
**  -framework OpenGL -framework AppKit
-----------------------------------------------------------------------------------------

** --------------- program structure -----------------------
** 1. read file
**          - get height(how many lines) of text
**          - get width(how many numbers in line)
**          - allocate memory for **int by using width and height (look your ft_strsplit() )
**          - read file and write number into **int matrix by using ft_strsplit() and atoi()
**          - ps: ft_wdcounter(line, ' ');  is a function witch count words in line look your ft_strsplit( )

** -------------------------------------
** 2. drawing line function (google Bresenham algorithm)
**             - find by how much we need to increase x and by how much we need to increase y
**                          by using float. Example:
**                                                       x = 2;           x1 = 4;
**                                                       y = 2;           y1 = 6;
**                                                       steps for x: 2
**                                                       steps for y: 4
**                          that means that y should grow 2 times faster than x
**                          every loop step: y += 1 and x += 0.5
**                          after 4 steps x and y will be equal with x1, y1
**                                       real x:y                   x:y                      pixels:    
**                    start:             2.0 : 2.0                  2:2                          .
**                    step1:             2.5 : 3.0                  2:3                          .
**                    step2:             3.0 : 4.0                  3:4                           .
**                    step3:             3.5 : 5.0                  3:5                           . 
**                    step4:             4.0 : 6.0                  4:6                            .
**
**                        that works because (float)2.5 turns to (int)2 in func. mlx_pixel_put()
** ------------------------------------------
** 3. function which draws lines between every dot
**                     - example:
**                                   0--      0--      0--      0
**                                    |         |         |          |
**                                   0--     10--   10--     0
**                                    |         |         |          |
**                                   0--     10--   10--     0
**                                    |         |         |          |
**                                   0--      0--     0--       0
**                                '--' and '|' are lines between dots 
**                              every dot has two lines (right and down):             0--
**                                                                                                                    |
** ----------------
** 4. adding 3D
**        - change coordinates by using isometric formulas:
**              x` = (x - y) * cos(angle)
**              y` = (x + y) * sin(angle) - z
**        - x` and y` are coordinates in 3D format (default angle 0.8)
** ----------------
** 5. adding bonuses (move, rotation, zoom)
**        - when you press button on keyboard the func. mlx_key_hook(win_ptr, deal_key, NULL);
**                   call the func. deal_key.
**        - In the deal key func. you have to change some parameters, clear the window with
**                   mlx_clear_window(mlx_ptr, win_ptr); and redraw the picture
** ----------------
** 6. error handling
**          - check if argc == 2
**          - check if file exists: fd = open(file_name, O_RDONLY)
**                         fd should be more than 0
** ----------------
** 7. fix leaks
**         - type leaks a.out or leaks fdf in your shell 		
*/

#include "../includes/fdf.h"
#include <mlx.h>

// int	deal_key(int key, fdf *data)
// {
// 	if (key == 126)
// 		data->shift_y -= 10;
// 	if (key == 125)
// 		data->shift_y += 10;
// 	if (key == 123)
// 		data->shift_x -= 10;
// 	if (key == 124)
// 		data->shift_x += 10;
// 	if (key == 53)
// 		exit (0);
// 	mlx_clear_window(data->mlx_ptr, data->win_ptr);
// 	draw(data);
// 	return (0);
// }

int	key_hook(int keycode, fdf *data)
{
	if (data)
		ft_printf("keycode -> %d", keycode);
	if (keycode == 65307 || keycode == 53)
	{
		printf("Closing window, bye!\n");
		exit(0);
	}
	else
		ft_printf("keycode -> %d\n", keycode);
	if ((keycode > 65360 && keycode < 65365) || (keycode < 127  && keycode > 122))
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	// if (keycode == 65362 || keycode == 126)
	// 	data->shift_y -= 10;
	// else if (keycode == 65361 || keycode == 125)
	// 	data->shift_y += 10;
	// else if (keycode == 65364 || keycode == 123)
	// 	data->shift_x -= 10;
	// else if (keycode == 65363 || keycode == 124)
	// 	data->shift_x += 10;
	// draw(data);
	return (0);
}

int	click_hook(int keycode)
{
	if (keycode < 10)
	{
		if (keycode > 3 && keycode < 8)
			printf("Mouse wheel spinning\n");
		else
			printf("Click!\n");
	}
	else
		printf("You pressed the %d key!\n", keycode);
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	fdf *data;
	img *image;

	if (argc > 1)
	{
		data = (fdf*)malloc(sizeof(fdf));	
		image = (img *)malloc(sizeof(img));
		read_file(argv[1], data);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 500, "FDF");
		image = mlx_new_image(data->mlx_ptr, 1920, 1080);
		image->addr = mlx_get_data_addr(image, &image->bits_per_pixel, &image->line_length, &image->endian);
		data->img = image;
		data->zoom = 20;
		draw(data);

		mlx_key_hook(data->win_ptr, key_hook, NULL);
		mlx_hook(data->win_ptr, 04, 1L<<2,  click_hook, NULL); // 04 keys+buttons | 02 only keyboard
		mlx_hook(data->win_ptr, 17, 0, exit_hook, NULL);
		mlx_loop(data->mlx_ptr);
	}
	return (0);
}