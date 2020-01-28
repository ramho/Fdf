/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:53:17 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/01/27 20:05:07 by rhoorntj         ###   ########.fr       */
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

typedef		struct	s_fdf
{
	int height;
	int width;
	int	**coord;
	int **tab_z;
}					t_fdf;

/*typedef		struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size;
	int		endian;
	int		bpp;
}					t_img;
*/


int	read_file(t_fdf *data,char *file);
int get_height_width(t_fdf *data, char *file);





#endif
