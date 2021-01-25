/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:53:17 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/17 15:00:47 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

# define W_WIDTH 1500
# define W_HEIGHT 1000

# define OFFSET 100
# define OFFSET_X 400
# define OFFSET_Y 50
# define OFFSET_IX 750
# define OFFSET_IY 300
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

typedef struct	s_fdf
{
	int			i;
	int			p;
	int			pixel;
	int			col;
	int			color;
	int			c[4];
	double		pix;
	int			height;
	int			width;
	double		**coord;
	int			**tab_z;
	double		**crdpro;
	void		*mlx_ptr;
	void		*win_ptr;
	double		dx;
	double		sx;
	double		dy;
	double		sy;
	double		err;
	double		e2;
}				t_fdf;

/*
** functions of free.c
*/

void			free_data(t_fdf *data);
int				free_error(t_fdf *data, int i);
int				free_tab(t_fdf *data, int i);
void			free_crdpro(t_fdf *data);
void			free_mlx_win(t_fdf *data);

/*
** functions of read.c
*/
int				read_file(t_fdf *data, char *file);
int				get_height_width(t_fdf *data, char *file);
int				get_z(int *z_line, char *line);
int				fill_coordxyz(t_fdf *data);
int				fill_h_w(t_fdf *data, char *line);

/*
** functions of projection.c
*/
void			draw_matrice(t_fdf *data);
void			draw_pixel(t_fdf *data);
int				projection_coord(t_fdf *data);
int				projection_iso(t_fdf *data);
int				projection_parallele(t_fdf *data);

/*
**	functions of deal_key.c
*/
int				deal_key(int key, t_fdf *data);
void			change_projection(int key, t_fdf *data);
void			move_arrows(int key, t_fdf *data);

/*
** functions of draw.c
*/
int				start_map(t_fdf *data);
void			draw_menu(t_fdf *data);
int				draw_map(t_fdf *data);
int				pix_size(t_fdf *data);

/*
** functions of line.c
*/
void			breshenhamx(t_fdf *data);
void			breshenhamy(t_fdf *data);
void			delta_calc_x(t_fdf *data);
void			delta_calc_y(t_fdf *data);

/*
**	functions in window.c
*/
void			set_hooks(t_fdf *data);
int				close_win(void *param);

/*
**	functions in color.c
*/
int				select_colorx(t_fdf *data);
int				select_colory(t_fdf *data);
#endif
