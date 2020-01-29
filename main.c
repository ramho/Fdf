/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:45:56 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/01/29 18:44:38 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	t_fdf *data;
	int i = 0;

	if(ac != 2)
	{
		ft_putendl("./fdf [file]");
		return(0);
	}

	data = malloc(sizeof(t_fdf));

	read_file(data, av[1]);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	//data->img->img_ptr = mlx_new_image(data->mlx_ptr,500, 500);
	//data->img->data = (int *)mlx_get_data_addr(data->img->img_ptr, &data->img->bpp, &data->img->size, &data->img->endian);

	draw_matrice(data);
	while (data->coord[i])
	{
		data->coordpro[i][0] = (coord[i][0] * cos(0.5) + (coord[i][1] * (-sin(0.5));
		data->coordpro[i][1] = (coord[i][0] * sin(0.5) + (coord[i][2] + (cos(0.5));
		data->coordpro[i][2] = 1;
		bres
		i++;
	}


	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 200, 200);
	//mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);

	return(0);
}
