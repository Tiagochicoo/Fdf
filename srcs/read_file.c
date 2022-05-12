/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:25:21 by tpereira          #+#    #+#             */
/*   Updated: 2022/04/19 18:19:04 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_height(char *filename)
{
	char	*line;
	int		fd;
	int		height;

	height = 0;
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_printf("Error: failed to open\n");
		exit(1);
	}
	while(get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	get_width(char *filename)
{
	int	width;
	int	fd;
	char *line;

	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_printf("Error: failed to open\n");
		exit(1);
	}
	get_next_line(fd, &line);
	width = (int)ft_word_count(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line, int width)
{
	int		i;
	char	**nums;

	i = 0;
	nums = ft_split(ft_strdup(line), " ");
	while(nums[i] && i < width)
	{
		z_line[i] = ft_atoi(nums[i]);
		//free(nums[i]);
		i++;
	}
	//free(nums);              ?????????????????? WHY ??????????????????
}

void	read_file(char *filename, fdf *data)
{
	int i;
	int	fd;
	char *line;

	i = 0;
	data->height = get_height(filename);
	data->width = get_width(filename);

	data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1));
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_printf("Error: failed to open\n");
		exit(1);
	}
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line, data->width);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
