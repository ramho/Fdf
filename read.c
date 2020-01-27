/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:52:07 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/01/27 20:13:51 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fill_coordxyz(t_fdf *data)
{
	int x;
	int y;
	int i;
printf("enter fill coord\n");
	y = 0;
	i = 0;
	while( y < data->height)
	{
		x = 0;
		while(x < data->width)
		{
			data->coord[i][0] = x;
			data->coord[i][1] = y;
			data->coord[i][2] = data->tab_z[x][y];
			x++;
			i++;
		}
		y++;
		i++;
	}
}

int		get_z(int *z_line, char *line, t_fdf *data)
{
	char **nums;
	int i;

	if(!(nums = ft_strsplit(line, ' ')))
		return (0);
	i = 0;
	//z_line = malloc(sizeof(int) + data->width + 1);
	while(nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
	return (1);
}

int get_height_width(t_fdf *data, char *file)
{
	int fd;
	int tmp;
	char *line;

	if((fd=open(file, O_RDONLY)) == -1)
		return(0);

	get_next_line(fd, &line);
	data->width = ft_countwords(line, ' ');
	free(line);
	data->height = 1;
	while(get_next_line(fd, &line))
	{
		tmp = data->width;
		data->width = ft_countwords(line, ' ');
		if(tmp != data->width)
			return(0);
		data->height++;
		free(line);
	}
	close(fd);
	return(1);
}


int	read_file(t_fdf *data,char *file)
{
	int fd;
	int i;
	char *line;

	if(!get_height_width(data, file))
		return(-1);
	if((fd = open(file, O_RDONLY)) == -1)
		return(-2);

	i = 0;
	data->tab_z= malloc(sizeof(int**) + (data->width * data->height) + 1);
	while((get_next_line(fd, &line)))
	{
		printf("i = %d\n", i);
		data->tab_z[i] = malloc(sizeof(int*) + data->width + 1);
		get_z(data->tab_z[i], line, data);
		free(line);
		i++;
	}
	close(fd);
//	data->tab_z[i] = NULL;
//	fill_coordxyz(data);
	return(1);
}
