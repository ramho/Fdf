/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:52:07 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/17 15:02:08 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		fill_coordxyz(t_fdf *data)
{
	int x;
	int y;
	int i;

	y = -1;
	i = 0;
	if (!(data->coord = malloc(sizeof(int **) *
		(data->width * data->height) + 1)))
		return (free_error(data, i));
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (!(data->coord[i] = malloc((sizeof(int *) * 3))))
				return (free_error(data, i));
			data->coord[i][0] = x;
			data->coord[i][1] = y;
			data->coord[i][2] = data->tab_z[y][x];
			i++;
		}
		free(data->tab_z[y]);
	}
	free(data->tab_z);
	return (1);
}

int		get_z(int *z_line, char *line)
{
	char	**nums;
	int		i;

	if (!(nums = ft_strsplit(line, ' ')))
		return (0);
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
	return (1);
}

int		fill_h_w(t_fdf *data, char *line)
{
	int tmp;

	tmp = data->width;
	data->width = ft_countwords(line, ' ');
	if (tmp != data->width)
		return (0);
	data->height++;
	free(line);
	return (1);
}

int		get_height_width(t_fdf *data, char *file)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	if (get_next_line(fd, &line) && line[0] == '\0')
	{
		free(line);
		close(fd);
		return (0);
	}
	data->width = ft_countwords(line, ' ');
	free(line);
	data->height = 1;
	while (get_next_line(fd, &line))
	{
		if (!fill_h_w(data, line))
			return (0);
	}
	close(fd);
	return (1);
}

int		read_file(t_fdf *data, char *file)
{
	int		fd;
	int		i;
	char	*line;

	if (!get_height_width(data, file))
		return (-1);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	i = 0;
	if (!(data->tab_z = malloc(sizeof(int**)
		* (data->width * data->height) + 1)))
		return (free_tab(data, i));
	while ((get_next_line(fd, &line)))
	{
		if (!(data->tab_z[i] = malloc(sizeof(int*) * data->width + 1)))
			return (free_tab(data, i));
		get_z(data->tab_z[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->tab_z[i] = NULL;
	if (!fill_coordxyz(data))
		return (-1);
	return (1);
}
