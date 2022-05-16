/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:27:30 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/16 18:40:06 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** --------------------- Resources-----------------------------
** --------------- 3D ------------------------------------------
**  x = (x - y) * cos(angle);
**  y = (x + y) * sin(angle) - z;
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
**        - In the deal key func. you have to change some dataeters, clear the window with
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
//#include <mlx.h>

void	print_menu(fdf*data)
{
	char *menu;

	menu = "How to use:";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 10, 0xffffff, menu);
	menu = "up, down, left, right: move picture";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 30, 0xffffff, menu);
	menu = "+, -: zoom";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 50, 0xffffff, menu);
	menu = "*, / : perspective";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 70, 0xffffff, menu);
	menu = "f: full screen mode";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, 90, 0xffffff, menu);
}

int	main(int argc, char **argv)
{
	fdf *data;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf map.fdf\n");
		exit(1);
	}
	data = (fdf*)malloc(sizeof(fdf));
	read_file(ft_strdup(argv[1]), data);
	init(data);
	draw(data);
	print_menu(data);
	actions(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}