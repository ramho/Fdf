/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_n_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:56:22 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/06 17:25:27 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	colors(t_fdf *data)
// {
// 	if(data->coord[data->i][2] > 0)
// 		return(0x2A2787);
// 	else if(data->coord[data->i][2] == 0)
// 			return(0xF80822);
// 	else if(data->coord[data->i][2] < 0)
// 		return(0x0A7369);
// 	return(0);
// }
//
// void	breshenham(double x0, double y0, double x1, double y1, t_fdf *data)
// {
// 	data->dx = abs((int)x1 - (int)x0);
// 	data->sx = x0 < x1 ? 1 : -1;
// 	data->dy = abs((int)y1 - (int)y0);
// 	data->sy = y0 < y1 ? 1 : -1;
// 	data->err = (data->dx > data->dy ? data->dx : -data->dy) / 2;
// 	while (1)
// 	{
// 		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0 , y0 , colors(data));
// 		if (x0 == x1 && y0 == y1)
// 			break;
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
