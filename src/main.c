/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:45:56 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/13 20:05:44 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// int 	free_error(t_fdf *data, int i)
// {
// 	if (tab_z)
// 		{
//
// 			free(tab_z);
// 		}
//
// 	free(&data->mlx_ptr);
// 	free(&data->win_ptr);
// 	return(-1);
// }

void	free_data(t_fdf *data)
{
	int i;

	i = (data->height * data->width) - 1 ;
	if (data->coord)
	{
		while(i >= 0)
		{
			free(data->coord[i]);
			i--;
		}
	}
	free(data->coord);
	i = (data->height * data->width) - 1 ;
	if (data->crdpro)
	{
			while(i >= 0)
			{
				free(data->crdpro[i]);
				i--;
			}
	}
	free(data->crdpro);
	// while (i < data->height * data->width)
	// {
	// 	free(data->coord[i]);
	// 	free(data->crdpro[i]);
	// 	i++;
	// }
	// free(data->coord);
	// free(data->crdpro);
	free(data->mlx_ptr);
	free(data->win_ptr);
}

int		main(int ac, char **av)
{
	t_fdf *data;

	if (ac != 2)
	{
		ft_putendl("usage [./fdf file]");
		return (-1);
	}
	if (!(ft_strstr(av[1], ".fdf")))
	{
		ft_putendl("[wrong file]");
		return (-1);
	}
	if (!(data = malloc(sizeof(t_fdf))))
		return (-1);
	if (read_file(data, av[1]) == -1)
		return (-1);
	if (start_map(data) == -1)
		return (-1);
	return (0);
}
