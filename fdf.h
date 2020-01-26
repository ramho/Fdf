#ifndef FDF_H
# define FDF_H

#include <stdio.h> //
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

//structure for image display
typedef		struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size;
	int		endian;
	int		bpp;
}					t_img;


//structure for windom and data
typedef		struct	s_fdf
{
	int	width;
	int	height;

	int **form;
	int	*project;

	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
}					t_fdf;

//stucture for chained list if easier
/*typedef		struct	s_matrice
{
	int	**form;
	int *projectxy;
	t_matrice	*next;
}					t_matrice*/

int			get_height_width(t_fdf *data, char *file_name);
int			fill_matrix(t_fdf *data, char *line, int i);
int			read_file(t_fdf *data, char *file_name);
void		breshenham(int x, int y, int x1, int y1, t_fdf *data);
int 		draw_matrice(t_fdf *data);

int	iso_y(int x,int y, int z);
int	iso_x(int x, int y);

#endif
