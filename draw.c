/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:19:08 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/01/25 16:40:07 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// 5 pix ca be a variable declared before, and say its (pix of my image)/#of colums

/*int  draw_matrice(t_fdf *data)
{
	int y;
	int x;
	int width_pix;
	int height_pix;
	int i;
	int j;

	y = 5;
	height_pix = data->height * y;
	while ( y <= height_pix)
	{
		x = 5;
		width_pix = data->width * x;
		while(x <= width_pix)
		{
			breshenham(x, y, x, y+5, data);
			breshenham(x, y, x + 5, y, data);
			if (y == height_pix)
			{
				breshenham(x, y + 5, x + 5, y + 5, data);
			}
			if (x == width_pix)
			{
				breshenham(x + 5, y , x + 5 , y + 5, data);
			}
			x+= 5;
			j++;
		}
		y+=5;
		i++;
	}
	return (1);
}*/

/*int  draw_matrice(t_fdf *data)
{
	int y;
	int x;
	int width_pix;
	int height_pix;
	int i;
	int j;

	y = 5;
	height_pix = data->height * y;
	while ( y <= height_pix)
	{
		x = 5;
		j=0;
		width_pix = data->width * x;
		while(x <= width_pix)
		{
			breshenham(iso_x(x, y), iso_y(x,y, data->matrix_z[i][j]), iso_x(x, y+5), iso_y(x,y+5, data->matrix_z[i][j]), data);
			breshenham(iso_x(x, y), iso_y(x,y, data->matrix_z[i][j]), iso_x(x+5, y), iso_y(x+5,y, data->matrix_z[i][j]), data);
			if (y == height_pix)
			{
				breshenham(iso_x(x, y+5), iso_y(x,y+5, data->matrix_z[i][j]),iso_x(x+5, y+5), iso_y(x+5,y+5, data->matrix_z[i][j]), data);
			}
			if (x == width_pix)
			{
				breshenham(iso_x(x+5, y), iso_y(x+5,y, data->matrix_z[i][j]) , iso_x(x+5, y+5) , iso_y(x+5,y+5, data->matrix_z[i][j]), data);
			}
			x+= 5;
			j++;
		}
		y+=5;
		i++;
	}
	return (1);
}*/

/*int 	dra_matrice(t_fdf *data)
{


}*/



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
		data->img->data[y1 * 500 + x1] = 0xFFFFFF;//
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
