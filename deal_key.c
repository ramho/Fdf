/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:30:07 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/06 17:24:23 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



// 
// void	move_arrows(int key, t_fdf *data)
// {
// 	int i;
//
// 	i = 0;
// 	mlx_clear_window ( data->mlx_ptr, data->win_ptr);
// 	while (i < data->height * data->width)
// 	{
// 		if (key == KEY_RIGHT)
// 			data->coord[i][0] *= 1.1;//(data->coord[i][0] * 0.1);
// 		 else if (key == KEY_LEFT)
// 		 	data->coord[i][0] *= 0.9;//(data->coord[i][0] * 0.1);
// 		else if (key == KEY_DOWN)
// 			data->coord[i][1] *= 1.1;// (data->coord[i][1] * 0.1);
// 		else if (key == KEY_UP)
// 			data->coord[i][1] *= 0.9;//(data->coord[i][1] * 0.1);
// 		i++;
// 	}
// 	draw_map(data);
// }

void	change_projection(int key, t_fdf *data)
{
	mlx_clear_window ( data->mlx_ptr, data->win_ptr);
	if (key == KEY_1)
		data->p = 1;
	else if (key == KEY_2)
		data->p = 2;
	draw_map(data);
}

int		deal_key(int key, t_fdf *data)
{
	if(key == ESC)
	// free ll
		exit(1);
	if(key == KEY_1 || key == KEY_2)
		change_projection(key, data);
	// else if(key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT
	// 	|| key == KEY_RIGHT)
	// 	move_arrows(key, data);

	return (0);
}
