/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:45:56 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/17 14:12:43 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		main(int ac, char **av)
{
	t_fdf *data;

	if (ac != 2)
	{
		ft_putendl("usage [./fdf file]");
		return (1);
	}
	if (!(ft_strstr(av[1], ".fdf")))
	{
		ft_putendl("[wrong file]");
		return (1);
	}
	if (!(data = malloc(sizeof(t_fdf))))
		return (1);
	if (read_file(data, av[1]) == -1)
	{
		ft_putendl("error");
		return (1);
	}
	if (start_map(data) == -1)
		return (1);
	return (0);
}
