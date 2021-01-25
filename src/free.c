/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:44:42 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/17 14:38:48 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_crdpro(t_fdf *data)
{
	int i;

	i = (data->height * data->width - 1);
	if (data->crdpro)
	{
		while (i >= 0)
		{
			free(data->crdpro[i]);
			i--;
		}
		free(data->crdpro);
	}
}

int		free_tab(t_fdf *data, int i)
{
	if (data->tab_z)
	{
		if (data->tab_z[i])
		{
			while (i >= 0)
			{
				free(data->tab_z[i]);
				i--;
			}
		}
		free(data->tab_z);
	}
	free(data);
	return (-1);
}

void	free_mlx_win(t_fdf *data)
{
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	if (data->win_ptr)
		free(data->win_ptr);
}

int		free_error(t_fdf *data, int i)
{
	int tmp;

	tmp = i;
	if (data->coord)
	{
		while (i >= 0)
		{
			free(data->coord[i]);
			i--;
		}
		free(data->coord);
	}
	i = tmp;
	if (data->crdpro)
	{
		while (i >= 0)
		{
			free(data->crdpro[i]);
			i--;
		}
		free(data->crdpro);
	}
	free_mlx_win(data);
	free(data);
	return (-1);
}

void	free_data(t_fdf *data)
{
	int i;

	i = (data->height * data->width) - 1;
	if (data->coord)
	{
		while (i >= 0)
		{
			free(data->coord[i]);
			i--;
		}
		free(data->coord);
	}
	i = (data->height * data->width) - 1;
	if (data->crdpro)
	{
		while (i >= 0)
		{
			free(data->crdpro[i]);
			i--;
		}
		free(data->crdpro);
	}
	free(data->mlx_ptr);
	free(data->win_ptr);
	free(data);
}
