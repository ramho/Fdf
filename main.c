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
	if (ac != 2)
			printf("Missing argument\n");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if(!(read_file(data, av[1])))
		printf("File error\n");
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	//data->img->img_ptr = mlx_new_image(data->mlx_ptr,500, 500);
	//data->img->data = (int *)mlx_get_data_addr(data->img->img_ptr, &data->img->bpp, &data->img->size, &data->img->endian);

//	draw_matrice(data);

	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 200, 200);
	//mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);
	return 0;
}
