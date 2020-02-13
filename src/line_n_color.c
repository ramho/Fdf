/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_n_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:56:22 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/13 17:37:23 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		select_colorx(t_fdf *data)
{
	if (data->col == 1)
	{
		if (data->coord[data->i][2] == data->coord[data->i + 1][2]
			&& data->coord[data->i][2] != 0)
			return (0xffff00);
		if (data->coord[data->i][2] < data->coord[data->i + 1][2]
			|| data->coord[data->i][2] > data->coord[data->i + 1][2])
			return (0x999966);
		if (data->coord[data->i][2] == data->coord[data->i + 1][2]
			&& data->coord[data->i][2] == 0)
			return (0x7300e6);
	}
	else if (data->col == 2)
	{
		if (data->coord[data->i][2] == data->coord[data->i + 1][2]
			&& data->coord[data->i][2] != 0)
			return (0x2A2787);
		if (data->coord[data->i][2] < data->coord[data->i + 1][2]
			|| data->coord[data->i][2] > data->coord[data->i + 1][2])
			return (0xDC87DF);
		if (data->coord[data->i][2] == data->coord[data->i + 1][2]
			&& data->coord[data->i][2] == 0)
			return (0x0A7369);
	}
	return (0);
}

int		select_colory(t_fdf *data)
{
	if (data->col == 1)
	{
		if (data->coord[data->i][2] == data->coord[data->i + data->width][2]
			&& data->coord[data->i][2] != 0)
			return (0xffff00);
		if (data->coord[data->i][2] < data->coord[data->i + data->width][2]
			|| data->coord[data->i][2] > data->coord[data->i + data->width][2])
			return (0x999966);
		if (data->coord[data->i][2] == data->coord[data->i + data->width][2]
			&& data->coord[data->i][2] == 0)
			return (0x7300e6);
	}
	else if (data->col == 2)
	{
		if (data->coord[data->i][2] == data->coord[data->i + data->width][2]
			&& data->coord[data->i][2] != 0)
			return (0x2A2787);
		if (data->coord[data->i][2] < data->coord[data->i + data->width][2]
			|| data->coord[data->i][2] > data->coord[data->i + data->width][2])
			return (0xDC87DF);
		if (data->coord[data->i][2] == data->coord[data->i + data->width][2]
			&& data->coord[data->i][2] == 0)
			return (0x0A7369);
	}
	return (0);
}

void	breshenhamx(t_fdf *data)
{
	int c[4];

	c[0] = (int)data->crdpro[data->i][0];
	c[1] = (int)data->crdpro[data->i][1];
	c[2] = (int)data->crdpro[data->i + 1][0];
	c[3] = (int)data->crdpro[data->i + 1][1];
	data->dx = abs(c[2] - c[0]);
	data->sx = c[0] < c[2] ? 1 : -1;
	data->dy = abs(c[3] - c[1]);
	data->sy = c[1] < c[3] ? 1 : -1;
	data->err = (data->dx > data->dy ? data->dx : -data->dy) * 0.5;
	while (c[0] != c[2]|| c[1] != c[3])
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, c[0], c[1], data->color);
		data->e2 = data->err;
		if (data->e2 > -data->dx)
		{
			data->err -= data->dy;
			c[0] += data->sx;
		}
		if (data->e2 < data->dy)
		{
			data->err += data->dx;
			c[1] += data->sy;
		}
	}
}

void	breshenhamy(t_fdf *data)
{
	int c[4];

	c[0] = (int)data->crdpro[data->i][0];
	c[1] = (int)data->crdpro[data->i][1];
	c[2] = (int)data->crdpro[data->i + data->width][0];
	c[3] = (int)data->crdpro[data->i + data->width][1];
	data->dx = abs(c[2] - c[0]);
	data->sx = c[0] < c[2] ? 1 : -1;
	data->dy = abs(c[3] - c[1]);
	data->sy = c[1] < c[3] ? 1 : -1;
	data->err = (data->dx > data->dy ? data->dx : -data->dy) * 0.5;
	while (c[0] != c[2]|| c[1] != c[3])
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, c[0], c[1], data->color);
		data->e2 = data->err;
		if (data->e2 > -data->dx)
		{
			data->err -= data->dy;
			c[0] += data->sx;
		}
		if (data->e2 < data->dy)
		{
			data->err += data->dx;
			c[1] += data->sy;
		}
	}
}
