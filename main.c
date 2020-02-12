/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:45:56 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/12 12:55:36 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	free_all(data)
// {
// 	int i;
//
// 	i = 0;
// 	while (i < data->height * data->width)
// 	{
// 		free(data->coord[i]);
// 		free(data->crdpro[i]);
// 		i++;
// 	}
// 	free(data->coord);
// 	free(data->crdpro);
// }

int main(int ac, char **av)
{
	t_fdf *data;

	if(ac != 2)
	{
		ft_putendl("usage [./fdf file]");
		return(0);
	}
	if(!(ft_strstr(av[1], ".fdf")))
	{
		ft_putendl("[wrong file]");
		return(0);
	}
	if(!(data = malloc(sizeof(t_fdf))))
		return(0);
	if (read_file(data, av[1]) == -1)
	 	return(-1);
	if(start_map(data) == -1)
		// free_all(data);
		return(-1);
	free(&data->mlx_ptr);
	free(&data->win_ptr);
	free(data);
	return(0);
}
