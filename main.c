/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:45:56 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/01/27 20:35:09 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	t_fdf *data;

	if(ac != 2)
	{
		ft_putendl("./fdf [file]");
		return(0);
	}

	 data = malloc(sizeof(t_fdf));
	// ft_memset((t_fdf*)data, 0, sizeof(data));
	read_file(data, av[1]);

	return(0);
	// t_fdf	*data;
	// if (ac != 2)
	// 		printf("Missing argument\n");
	// data = (t_fdf *)malloc(sizeof(t_fdf));
	// if(!(read_file(data, av[1])))
	// 	printf("File error\n");
	// return(0);
}
