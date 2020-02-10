/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:53:17 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/10 14:53:39 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
# define FDF_H

#include <stdio.h> //
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

# define W_WIDTH 1500
# define W_HEIGHT 1000

# define OFFSET 100
//# define OFFSET_I 200
# define PIX 20
# define ESC 53

# define KEY_1 83
# define KEY_2 84
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

typedef		struct	s_img
{
	void	*img_ptr;
	int	*info;
	int		size;
	int		endian;
	int		bpp;
}					t_img;

typedef		struct	s_fdf
{
	int			i;
	int 		p;
	double 		pix;

	int 		height;
	int 		width;
	double		**coord;
	int 		**tab_z;
	double 		**crdpro;

	void		*mlx_ptr;
	void		*win_ptr;

	t_img		img;

	double	dx;
	double	sx;
	double	dy;
	double	sy;
	double	err;
	double	e2;
}					t_fdf;

/*
** functions of read.c
*/
int		read_file(t_fdf *data,char *file);
int		get_height_width(t_fdf *data, char *file);
int		get_z(int *z_line, char *line, t_fdf *data);
int		fill_coordxyz(t_fdf *data);

/*
** functions of projection.c
*/
void	breshenham(double x0, double y0, double x1, double y1, t_fdf *data);
void	draw_matrice(t_fdf *data);
void	projection_coord(t_fdf *data);
void	projection_iso(t_fdf *data);
void	projection_parallele(t_fdf *data);
void	projection_stairway_to_heaven(t_fdf *data);
void	projection_triangle_of_samba(t_fdf *data);

/*
**	functions of deal_key.c
*/
int		deal_key(int key, t_fdf *data);
void	change_projection(int key, t_fdf *data);
void	move_arrows(int key, t_fdf *data);

/*
** functions of draw.c
*/
void	start_map(t_fdf *data);
void	draw_menu(t_fdf *data);
void	draw_map(t_fdf *data);
void	init_map(t_fdf *data);

/*
** functions of line_n_color
*/
int		colors(t_fdf *data);
void	breshenham(double x0, double y0, double x1, double y1, t_fdf *data);


#endif
