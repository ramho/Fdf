#include "fdf.h"

void		get_height_width(t_fdf *data, char *file_name)
{
	char *line;
	int width_check;
	int fd;

	fd = open(file_name, O_RDONLY);
	data->height = 0;
	data->width = 0;
	while((get_next_line(fd, &line) != 0))
	{
		width_check = ft_countwords(line, ' ');
		if(width_check > data->width)
			data->width = width_check;
		data->height++;
		free(line);
	}
	close(fd);
}

int	fill_matrix(int *z_line, char *line)
{
	char **nums;
	int i;

	if(!(nums = ft_strsplit(line, ' ')))
		return (-1);
	i = 0;
	while(nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
	return (1);
}

int	read_file(t_fdf	*data, char *file_name)
{
	int fd;
	char *line;
	int i;

	get_height_width(data, file_name);
	if(!(data->matrix_z = (int **)malloc(sizeof(int *) * (data->height + 1))))
			return (0); //free something ?
	i = 0;
	while (i <= data->height) //free something?
	{
		if(!(data->matrix_z[i++] = (int *)malloc(sizeof(int) * (data->width + 1))))
				return (0);
	}
	fd = open(file_name, O_RDONLY);
	i = 0;
	while((get_next_line(fd, &line)))
	{
		fill_matrix(data->matrix_z[i], line);
		free(line);
		i++;
	}	
	close(fd);
	data->matrix_z[i] = NULL;
	return (1);
}
