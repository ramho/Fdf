/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_n_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:56:22 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/17 13:51:53 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	delta_calc_y(t_fdf *data)
{
	data->c[0] = (int)data->crdpro[data->i][0];
	data->c[1] = (int)data->crdpro[data->i][1];
	data->c[2] = (int)data->crdpro[data->i + data->width][0];
	data->c[3] = (int)data->crdpro[data->i + data->width][1];
}

void	delta_calc_x(t_fdf *data)
{
	data->c[0] = (int)data->crdpro[data->i][0];
	data->c[1] = (int)data->crdpro[data->i][1];
	data->c[2] = (int)data->crdpro[data->i + 1][0];
	data->c[3] = (int)data->crdpro[data->i + 1][1];
}

void	breshenhamx(t_fdf *data)
{
	delta_calc_x(data);
	data->dx = abs(data->c[2] - data->c[0]);
	data->sx = data->c[0] < data->c[2] ? 1 : -1;
	data->dy = abs(data->c[3] - data->c[1]);
	data->sy = data->c[1] < data->c[3] ? 1 : -1;
	data->err = (data->dx > data->dy ? data->dx : -data->dy) * 0.5;
	while (data->c[0] != data->c[2] || data->c[1] != data->c[3])
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->c[0],
			data->c[1], data->color);
		data->e2 = data->err;
		if (data->e2 > -data->dx)
		{
			data->err -= data->dy;
			data->c[0] += data->sx;
		}
		if (data->e2 < data->dy)
		{
			data->err += data->dx;
			data->c[1] += data->sy;
		}
	}
}

void	breshenhamy(t_fdf *data)
{
	delta_calc_y(data);
	data->dx = abs(data->c[2] - data->c[0]);
	data->sx = data->c[0] < data->c[2] ? 1 : -1;
	data->dy = abs(data->c[3] - data->c[1]);
	data->sy = data->c[1] < data->c[3] ? 1 : -1;
	data->err = (data->dx > data->dy ? data->dx : -data->dy) * 0.5;
	while (data->c[0] != data->c[2] || data->c[1] != data->c[3])
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->c[0],
			data->c[1], data->color);
		data->e2 = data->err;
		if (data->e2 > -data->dx)
		{
			data->err -= data->dy;
			data->c[0] += data->sx;
		}
		if (data->e2 < data->dy)
		{
			data->err += data->dx;
			data->c[1] += data->sy;
		}
	}
}
