/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:45:56 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/06 17:47:56 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	read_file(data, av[1]); // handle errors
	start_map(data);
	free(data->coord); // free coord[i] before
	free(&data->mlx_ptr);
	free(&data->win_ptr);
	return(0);
}
