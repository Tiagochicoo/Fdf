/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:27:30 by tpereira          #+#    #+#             */
/*   Updated: 2021/09/16 20:45:55 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int close(int keycode, t_data mlx)
{
	if (keycode == 27)
	{
		mlx_destroy_window(mlx.mlx, mlx.mlx_win);
	}
}

int	main(void)
{
	t_data	mlx;
	t_data	mlx_win;
	t_data	img;
	t_data	str;
	int		x;
	int		y;
	int		x2;
	int		y2;

	x = 100;
	y = 100;
	x2 = 510;
	y2 = 100;
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 1024, 768, "Hello world!");
	img.img = mlx_new_image(mlx.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	// first square
	while (x < 500 && y < 500)
	{
		my_mlx_pixel_put(&img, x, 100, 0xFFABCDEF);
		my_mlx_pixel_put(&img, x, 500, 0xFFABCDEF);
		my_mlx_pixel_put(&img, 100, y, 0xFFABCDEF);
		my_mlx_pixel_put(&img, 500, y, 0xFFABCDEF);
		x++;
		y++;
	}
	
	while (x2 < 1000 && y2 < 500)
	{
		my_mlx_pixel_put(&img, x2, 100, 0xFFFFFFFF);
		my_mlx_pixel_put(&img, x2, 500, 0xFFFFFFFF);
		my_mlx_pixel_put(&img, 510, y2, 0xFFFFFFFF);
		my_mlx_pixel_put(&img, 910, y2, 0xFFFFFFFF);
		x2++;
		y2++;
	}

	//mlx_hook(mlx.mlx_win, 2, (1L << 1), close(27, &mlx, &mlx_win), &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 1, 1);
	mlx_string_put(mlx.mlx, mlx.mlx_win, 250, 250, 0xFFABCDEF, "square 1");
	mlx_string_put(mlx.mlx, mlx.mlx_win, 700, 250, 0xFFABCDEF, "square 2");
	mlx_key_hook(mlx.mlx_win, close(42, mlx), &mlx);
	mlx_loop(mlx.mlx);

}