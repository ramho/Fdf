/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:22:04 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/13 18:41:29 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int 	close_win(void	*param)
{
	t_fdf	*data;

	data = (t_fdf *)param;
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_data(data);
	exit(EXIT_SUCCESS);
}

void	set_hooks(t_fdf *data)
{
	mlx_hook(data->win_ptr, 17, 0, close_win, data);
}

int		pix_size(t_fdf *data)
{
	if (W_WIDTH < W_HEIGHT)
		return (data->pix = W_WIDTH / data->width);
	else
		return (data->pix = W_HEIGHT / data->width);
}

int		draw_map(t_fdf *data)
{
	draw_menu(data);
	if (data->p == 0)
	{
		if (projection_coord(data) == -1)
			return (-1);
	}
	else if (data->p == 1)
	{
		if (projection_iso(data) == -1)
			return (-1);
	}
	else if (data->p == 2)
	{
		if (projection_parallele(data) == -1)
			return (-1);
	}
	return (0);
}

void	draw_menu(t_fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, "\"FDF\"");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 30, 0xFFFFFF, "by");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 50, 0xFFFFFF, "rhoorntj");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 80, 0xFFFFFF,
		"Projection");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 80, 0xFFFFFF,
		"ISO = 1 PARA = 2");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 100, 0xFFFFFF,
		"Color change");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 100, 0xFFFFFF, "C or V");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 120, 0xFFFFFF, "Altitute");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 120, 0xFFFFFF, "A or Z");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 140, 0xFFFFFF, "Move");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 150, 140, 0xFFFFFF, "arrows");
}

int		start_map(t_fdf *data)
{
	if (!(data->mlx_ptr = mlx_init()))
		return (-1);
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr, W_WIDTH,
		W_HEIGHT, "FDF")))
		return (-1);
	data->p = 0;
	data->col = 1;
	data->pixel = 0;
	data->pix = pix_size(data);
	if (draw_map(data) == -1)
		return (-1);
	mlx_key_hook(data->win_ptr, deal_key, (void*)data);
	set_hooks(data);
	mlx_loop(data->mlx_ptr);
	return (1);
}
