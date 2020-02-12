/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:30:07 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/12 15:07:55 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_arrows(int key, t_fdf *data)
{
	int i;

	i = 0;
	mlx_clear_window ( data->mlx_ptr, data->win_ptr);
	while (i < data->height * data->width)
	{
		if (key == KEY_RIGHT)
			data->crdpro[i][0] += 5;
		 else if (key == KEY_LEFT)
		 	data->crdpro[i][0] -= 5;
		else if (key == KEY_DOWN)
			data->crdpro[i][1] += 5;
		else if (key == KEY_UP)
			data->crdpro[i][1] -= 5;
		i++;
	}
	draw_menu(data);
	draw_matrice(data);
}

void	change_altitude(int key, t_fdf *data)
{
	int i;

	i = 0;
	mlx_clear_window ( data->mlx_ptr, data->win_ptr);
	while (i < data->height * data->width)
	{
		if(key == KEY_A)
			data->coord[i][2] *= 1.1;
		else if(key == KEY_Z)
		data->coord[i][2] /= 1.1;
		i++;
	}
	draw_menu(data);
	draw_map(data);
}

void	change_colors(int key, t_fdf *data)
{
	mlx_clear_window ( data->mlx_ptr, data->win_ptr);
	if (key == KEY_C)
		data->col = 1;
	else if (key == KEY_V)
		data->col = 2;
	draw_menu(data);
	draw_matrice(data);
}

void	change_projection(int key, t_fdf *data)
{
	mlx_clear_window ( data->mlx_ptr, data->win_ptr);
	if (key == KEY_1)
		data->p = 1;
	else if (key == KEY_2)
		data->p = 2;
	else if (key == KEY_3)
		data->pixel = 3;
	else if (key == KEY_MAX)
		data->pix += 0.1;
	else if (key == KEY_MIN)
		data->pix -= 0.1;
	draw_map(data);
}

int		deal_key(int key, t_fdf *data)
{
	if(key == ESC)
	// free ll
		exit(1);
	else if(key == KEY_1 || key == KEY_2 || key == KEY_MIN
		|| key == KEY_MAX )
		change_projection(key, data);
	else if(key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT
		|| key == KEY_RIGHT)
		move_arrows(key, data);
	else if (key == KEY_A || key == KEY_Z)
		change_altitude(key, data);
	else if (key == KEY_C || key == KEY_V)
		change_colors(key,data);
	return (0);
}
