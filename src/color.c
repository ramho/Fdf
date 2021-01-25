/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:15:14 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/17 13:22:51 by rhoorntj         ###   ########.fr       */
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
