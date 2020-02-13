/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:39:23 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/13 17:37:23 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		projection_coord(t_fdf *data)
{
	int i;

	i = 0;
	if (!(data->crdpro = malloc(sizeof(int **) *
		(data->width * data->height) + 1)))
		return (-1);
	while (i < data->height * data->width)
	{
		if (!(data->crdpro[i] = malloc((sizeof(int *) * 3))))
			return (-1);
		data->crdpro[i][0] = data->coord[i][0] * data->pix + OFFSET_X;
		data->crdpro[i][1] = data->coord[i][1] * data->pix + OFFSET_Y;
		i++;
	}
	draw_matrice(data);
	return (1);
}

int		projection_iso(t_fdf *data)
{
	int i;

	i = 0;
	if (!(data->crdpro = malloc(sizeof(int **) *
		(data->width * data->height) + 1)))
		return (-1);
	while (i < data->height * data->width)
	{
		if (!(data->crdpro[i] = malloc((sizeof(int *) * 3))))
			return (-1);
		data->crdpro[i][0] = ((0.5 * data->coord[i][0]) -
			(0.5 * data->coord[i][1]));
		data->crdpro[i][1] = (-1 * data->coord[i][2] +
			((0.5 / 2) * data->coord[i][0]) + ((0.5 / 2) * data->coord[i][1]));
		data->crdpro[i][0] = data->crdpro[i][0] * data->pix + OFFSET_Ix;
		data->crdpro[i][1] = data->crdpro[i][1] * data->pix + OFFSET_Iy;
		i++;
	}
	draw_matrice(data);
	return (1);
}

int		projection_parallele(t_fdf *data)
{
	int i;

	i = 0;
	if (!(data->crdpro = malloc(sizeof(int **) *
	(data->width * data->height) + 1)))
		return (-1);
	while (i < data->height * data->width)
	{
		if (!(data->crdpro[i] = malloc((sizeof(int *) * 3))))
			return (-1);
		data->crdpro[i][0] = data->coord[i][0] + 0.5 * data->coord[i][2];
		data->crdpro[i][1] = data->coord[i][1] + (0.5 / 2) * data->coord[i][2];
		data->crdpro[i][0] = data->crdpro[i][0] * data->pix + OFFSET_X;
		data->crdpro[i][1] = data->crdpro[i][1] * data->pix + OFFSET_Y;
		i++;
	}
	draw_matrice(data);
	return (1);
}

void	draw_matrice(t_fdf *data)
{
	int y;
	int x;

	data->i = 0;
	y = -1;
	while (++y <= data->height - 1)
	{
		x = -1;
		while (++x <= data->width - 1)
		{
			if (data->coord[data->i][0] < data->width - 1)
			{
				data->color = select_colorx(data);
				breshenhamx(data);
			}
			if (data->coord[data->i][1] < data->height - 1)
			{
				data->color = select_colory(data);
				breshenhamy(data);
			}
			data->i++;
		}
	}
}
