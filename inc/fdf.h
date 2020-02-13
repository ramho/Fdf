/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:53:17 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/13 18:53:16 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
# define FDF_H

#include <stdio.h> //
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"

# define W_WIDTH 1500
# define W_HEIGHT 1000

# define OFFSET 100
# define OFFSET_X 400
# define OFFSET_Y 50
# define OFFSET_Ix 750
# define OFFSET_Iy 300
# define PIX 20
# define ESC 53

# define KEY_1 83
# define KEY_2 84
# define KEY_3 85
# define KEY_A 0
# define KEY_Z 6
# define KEY_C 8
# define KEY_V 9
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_MIN 78
# define KEY_MAX 69

typedef		struct	s_img
{
	void	*img_ptr;
	int		*info;
	int		size;
	int		endian;
	int		bpp;
}					t_img;

typedef		struct	s_fdf
{
	int			i;
	int 		p;
	int 		pixel;
	int 		col;
	int 		color;
	double 		pix;

	int 		height;
	int 		width;
	double		**coord;
	int 		**tab_z;
	double 		**crdpro;

	void		*mlx_ptr;
	void		*win_ptr;

	char 		*img_str;

	t_img		img;

	double	dx;
	double	sx;
	double	dy;
	double	sy;
	double	err;
	double	e2;
}					t_fdf;

/*
** functions of main.c
*/
void		free_data(t_fdf *data);
// int 	free_error(t_fdf *data, int i);
int 	main(int ac, char **av);

/*
** functions of read.c
*/
int		read_file(t_fdf *data,char *file);
int		get_height_width(t_fdf *data, char *file);
int		get_z(int *z_line, char *line);
int		fill_coordxyz(t_fdf *data);

/*
** functions of projection.c
*/
void	draw_matrice(t_fdf *data);
void	draw_pixel(t_fdf *data);
int		projection_coord(t_fdf *data);
int		projection_iso(t_fdf *data);
int		projection_parallele(t_fdf *data);

/*
**	functions of deal_key.c
*/
int		deal_key(int key, t_fdf *data);
void	change_projection(int key, t_fdf *data);
void	move_arrows(int key, t_fdf *data);

/*
** functions of draw.c
*/
int		start_map(t_fdf *data);
void	draw_menu(t_fdf *data);
int		draw_map(t_fdf *data);
void	init_map(t_fdf *data);

/*
** functions of line_n_color
*/
void	breshenhamx(t_fdf *data);
void	breshenhamy(t_fdf *data);
int 	select_colorx(t_fdf *data);
int 	select_colory(t_fdf *data);

#endif
