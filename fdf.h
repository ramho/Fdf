#ifndef FDF_H
# define FDF_H

#include <stdio.h> //
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef		struct	s_fdf
{
	int	width;
	int	height;
	int	**matrix_z;

	void	*mlx_ptr;
	void	*win_ptr;
}					t_fdf;

void		get_height_width(t_fdf *data, char *file_name);
int			fill_matrix(int *z_line, char *line);
int			read_file(t_fdf *data, char *file_name);
void		breshenham(int x, int y, int x1, int y1, t_fdf *data);
int 		draw_matrice(t_fdf *data);

int	iso_y(int x,int y, int z);
int	iso_x(int x, int y);

#endif
