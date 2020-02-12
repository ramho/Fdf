/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_n_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:56:22 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/12 15:19:35 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		colors(t_fdf *data)
{
	if (data->col == 1)
	{
		if (data->coord[data->i][2] > 0)
			return (0x2A2787);
		else if (data->coord[data->i][2] == 0)
			return (0xF80822);
		else if (data->coord[data->i][2] < 0)
			return (0x0A7369);
	}
	else if (data->col == 2)
	{
		if (data->coord[data->i][2] > 0)
			return (0xffff00);
		else if (data->coord[data->i][2] == 0)
			return (0x999966);
		else if (data->coord[data->i][2] < 0)
			return (0x7300e6);
	}
	return(0);
}

// void	breshenham(int x0, int y0, int x1, int y1, t_fdf *data)
// {
// 	data->dx = abs((int)x1 - (int)x0);
// 	data->sx = x0 < x1 ? 1 : -1;
// 	data->dy = abs((int)y1 - (int)y0);
// 	data->sy = y0 < y1 ? 1 : -1;
// 	data->err = (data->dx > data->dy ? data->dx : -data->dy) * 0.5;
//  	while (x0 != x1 || y0 != y1)
// 	{
// 		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, colors(data));
// 		data->e2 = data->err;
// 		if (data->e2 > -data->dx)
// 		{
// 			data->err -= data->dy;
// 			x0 += data->sx;
// 		}
// 		if (data->e2 < data->dy)
// 		{
// 			data->err += data->dx;
// 			y0 += data->sy;
// 		}
// 	}
// }

// void	breshenhamx(int x0, int y0, int x1, int y1, t_fdf *data)
// {
// 	data->dx = abs((int)x1 - (int)x0);
// 	data->sx = x0 < x1 ? 1 : -1;
// 	data->dy = abs((int)y1 - (int)y0);
// 	data->sy = y0 < y1 ? 1 : -1;
// 	data->err = (data->dx > data->dy ? data->dx : -data->dy) * 0.5;
//  	while (x0 != x1 || y0 != y1)
// 	{
// 		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, colors(data));
// 		data->e2 = data->err;
// 		if (data->e2 > -data->dx)
// 		{
// 			data->err -= data->dy;
// 			x0 += data->sx;
// 		}
// 		if (data->e2 < data->dy)
// 		{
// 			data->err += data->dx;
// 			y0 += data->sy;
// 		}
// 	}
// }
//
// void	breshenhamy(int x0, int y0, int x1, int y1, t_fdf *data)
// {
// 	data->dx = abs((int)x1 - (int)x0);
// 	data->sx = x0 < x1 ? 1 : -1;
// 	data->dy = abs((int)y1 - (int)y0);
// 	data->sy = y0 < y1 ? 1 : -1;
// 	data->err = (data->dx > data->dy ? data->dx : -data->dy) * 0.5;
//  	while (x0 != x1 || y0 != y1)
// 	{
// 		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, colors(data));
// 		data->e2 = data->err;
// 		if (data->e2 > -data->dx)
// 		{
// 			data->err -= data->dy;
// 			x0 += data->sx;
// 		}
// 		if (data->e2 < data->dy)
// 		{
// 			data->err += data->dx;
// 			y0 += data->sy;
// 		}
// 	}
// }

void	breshenhamx(/*int x0, int y0, int x1, int y1,*/ t_fdf *data)  //breshenhamx(data->crdpro[data->i][0], data->crdpro[data->i][1], data->crdpro[data->i + 1][0], data->crdpro[data->i + 1][1],data);
{
	int x0;
	int y0;

	x0 = data->crdpro[data->i][0];
	y0 = data->crdpro[data->i][1];
	data->dx = abs(((int)data->crdpro[data->i + 1][0]) - ((int)x0));
	data->sx = x0 < data->crdpro[data->i + 1][0] ? 1 : -1;
	data->dy = abs(((int)data->crdpro[data->i + 1][1]) - ((int)y0));
	data->sy = y0 < data->crdpro[data->i + 1][1] ? 1 : -1;
	data->err = (data->dx > data->dy ? data->dx : -data->dy) * 0.5;
 	while (x0!= data->crdpro[data->i + 1][0] || y0 != data->crdpro[data->i + 1][1])
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, colors(data));
		data->e2 = data->err;
		if (data->e2 > -data->dx)
		{
			data->err -= data->dy;
			x0+= data->sx;
		}
		if (data->e2 < data->dy)
		{
			data->err += data->dx;
			y0 += data->sy;
		}
	}
}

void	breshenhamy(/*int x0, int y0, int x1, int y1,*/ t_fdf *data)
{
	int x0;
	int y0;
	x0 = data->crdpro[data->i][0];
	y0 = data->crdpro[data->i][1];
	data->dx = abs(((int)data->crdpro[data->i + data->width][0]) - ((int)x0));
	data->sx = x0 < data->crdpro[data->i + data->width][0] ? 1 : -1;
	data->dy = abs(((int)data->crdpro[data->i + data->width][1]) - ((int)y0));
	data->sy = y0 < data->crdpro[data->i + data->width][1] ? 1 : -1;
	data->err = (data->dx > data->dy ? data->dx : -data->dy) * 0.5;
 	while (x0!= data->crdpro[data->i + data->width][0] || y0 != data->crdpro[data->i + data->width][1])
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, colors(data));
		data->e2 = data->err;
		if (data->e2 > -data->dx)
		{
			data->err -= data->dy;
			x0+= data->sx;
		}
		if (data->e2 < data->dy)
		{
			data->err += data->dx;
			y0 += data->sy;
		}
	}
}
