#include "fdf.h"

int		get_height_width(t_fdf *data, char *file_name)
{
	char *line;
	//int width_check;
	int fd;

	//width_check = 0;
	fd = open(file_name, O_RDONLY);
	data->height = 0;
	data->width = 0;
	while((get_next_line(fd, &line) != 0))
	{
		data->width = ft_countwords(line, ' ');
		data->height++;
		free(line);
	}
	close(fd);
	return(1);
}

int	fill_matrix(t_fdf *data, char *line, int i)
{
	char **nums;
	int a;
	int b;
	int c;
	int d;

	a = 0;
	d = 0;
	if(!(nums = ft_strsplit(line, ' ')))
		return (-1);
	while (a < data->height)
	{
		b = 0;
		while (b < data->width)
		{
			data->form[i][b] = data->width;
			data->form[i][a] = data->height;
			data->form[i][c] = ft_atoi(nums[d][b]);
			printf("Test05\n");
			b++;
			d++;
		}
		free(nums[d]);
		a++;
	}
	free(nums);
	i = 0;
	/*while(z_line[i])
	{
		z_line[i] = z_line[i] + 50;
		i++;
	}*/
	return (1);
}

int	read_file(t_fdf	*data, char *file_name)
{
	int fd;
	char *line;
	int i;

	if(!(get_height_width(data, file_name)))
		return(0);
	if(!(data->form = (int **)malloc(sizeof(int *) * (data->height + 1))))
			return (0); //free something ?
	i = 0;
	while (i <= data->height) //free something?
	{
		if(!(data->form[i++] = (int *)malloc(sizeof(int) * (data->width + 1))))
				return (0);
	}
	fd = open(file_name, O_RDONLY);
	i = 0;
	while((get_next_line(fd, &line)))
	{
		fill_matrix(data, line, i);
		free(line);
		i++;
	}
	close(fd);
	data->form[i] = NULL;
	return (1);
}
