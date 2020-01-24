#include "fdf.h"
#include <stdio.h>//

int		deal_key(int key, void *data)
{
	printf("%d", key);
	return(0);
}

int  main(int ac, char **av)
{
	t_fdf	*data;
	int ret = 0; //
	if (ac == 2)
	{
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(data, av[1]);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	draw_matrice(data);
	mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);
	}
	else
		printf("Missing argument\n");
	return 0;
}
