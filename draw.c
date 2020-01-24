/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:19:08 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/01/21 19:04:500 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// 50 pix ca be a variable declared before, and say its (pix of my image)/#of colums

/*int  draw_matrice(t_fdf *data)
{
	int y;
	int x;
	int width_pix;
	int height_pix;
	int i;
	int j;

	y = 50;
	height_pix = data->height * y;
	while ( y <= height_pix)
	{
		x = 50;
		width_pix = data->width * x;
		while(x <= width_pix)
		{
			breshenham(x, y, x, y+50, data);
			breshenham(x, y, x + 50, y, data);
			if (y == height_pix)
			{
				breshenham(x, y + 50, x + 50, y + 50, data);
			}
			if (x == width_pix)
			{
				breshenham(x + 50, y , x + 50 , y + 50, data);
			}
			x+= 50;
			j++;
		}
		y+=50;
		i++;
	}
	return (1);
}*/

int  draw_matrice(t_fdf *data)
{
	int y;
	int x;
	int width_pix;
	int height_pix;
	int i;
	int j;

	y = 50;
	height_pix = data->height * y;
	while ( y <= height_pix)
	{
		x = 50;
		j=0;
		width_pix = data->width * x;
		while(x <= width_pix)
		{
			breshenham(iso_x(x, y), iso_y(x,y, data->matrix_z[i][j]), iso_x(x, y+50), iso_y(x,y+50, data->matrix_z[i][j]), data);
			breshenham(iso_x(x, y), iso_y(x,y, data->matrix_z[i][j]), iso_x(x+50, y), iso_y(x+50,y, data->matrix_z[i][j]), data);
			if (y == height_pix)
			{
				breshenham(iso_x(x, y+50), iso_y(x,y+50, data->matrix_z[i][j]),iso_x(x+50, y+50), iso_y(x+50,y+50, data->matrix_z[i][j]), data);
			}
			if (x == width_pix)
			{
				breshenham(iso_x(x+50, y), iso_y(x+50,y, data->matrix_z[i][j]) , iso_x(x+50, y+50) , iso_y(x+50,y+50, data->matrix_z[i][j]), data);
			}
			x+= 50;
			j++;
		}
		y+=50;
		i++;
	}
	return (1);
}


void	breshenham(int x0, int y0, int x1, int y1, t_fdf *data)
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;
	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, 0x0000FF);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}
