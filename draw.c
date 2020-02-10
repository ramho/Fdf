/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:22:04 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/10 14:34:10 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	pix_size(t_fdf *data)
{
	if (W_WIDTH < W_HEIGHT)
		return(data->pix = W_WIDTH / data->width);
	else
		return(data->pix = W_HEIGHT / data->width);
}

void	draw_map(t_fdf *data)
{
	draw_menu(data);
	if (data->p == 0)
		projection_coord(data);
	else if (data->p == 1)
		projection_iso(data);
	else if (data->p == 2)
		projection_parallele(data);
	draw_matrice(data);
}

void	draw_menu(t_fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, "\"FDF\"");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 30, 0xFFFFFF, "by");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 50, 0xFFFFFF, "rhoorntj");
}

void	start_map(t_fdf *data)
{
	data->mlx_ptr = mlx_init();// protect
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT, "FDF"); // protect
	data->p = 1;
	printf("width = %d\n", data->width);
	data->pix = pix_size(data);
	printf("pix_size = %f\n", data->pix);
	draw_map(data);
	mlx_key_hook(data->win_ptr, deal_key, (void*)data);
	mlx_loop(data->mlx_ptr);
}
