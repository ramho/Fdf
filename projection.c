/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:39:23 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/10 14:50:23 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection_coord(t_fdf *data)
{
	int i;

	i = 0;
	data->crdpro = malloc(sizeof(int **) * (data->width * data->height) + 1);
	while (i < data->height * data->width)
	{
		data->crdpro[i] = malloc((sizeof(int *) * 3));
		data->crdpro[i][0] = data->coord[i][0] * data->pix + OFFSET;
		data->crdpro[i][1] = data->coord[i][1] * data->pix + OFFSET;
		++i;
	}
}

void	projection_iso(t_fdf *data)
{
	int i;

	i = 0;
	data->crdpro = malloc(sizeof(int **) * (data->width * data->height) + 1);
	while (i < data->height * data->width)
	{
		//printf("in iso coord %d = [%f - %f]\n",i,data->coord[i][0], data->coord[i][1] );
		data->crdpro[i] = malloc((sizeof(int *) * 3));
		data->crdpro[i][0] = ((0.5 * data->coord[i][0]) - (0.5 * data->coord[i][1]));
		data->crdpro[i][1] = (-1 * data->coord[i][2] + ((0.5/2) * data->coord[i][0]) + ((0.5/2) * data->coord[i][1]));
		data->crdpro[i][0] = data->crdpro[i][0] * data->pix + OFFSET;
		data->crdpro[i][1] = data->crdpro[i][1] * data->pix + OFFSET;
		printf("in iso crdppo %d = [%f - %f]\n",i, data->crdpro[i][0] , data->crdpro[i][1]);
		++i;
	}
	printf("out of iso\n");
}

void	projection_parallele(t_fdf *data)
{
	int i;

	i = 0;
	data->crdpro = malloc(sizeof(int **) * (data->width * data->height) + 1);
	while (i < data->height * data->width)
	{
		data->crdpro[i] = malloc((sizeof(int *) * 3));
		data->crdpro[i][0] = data->coord[i][0] + 0.5 * data->coord[i][2]
		/*+ OFFSET*/;
		data->crdpro[i][1] = data->coord[i][1] + (0.5/2) *data->coord[i][2]
		/*+ OFFSET*/;
		data->crdpro[i][0] = data->crdpro[i][0] * data->pix + OFFSET;
		data->crdpro[i][1] = data->crdpro[i][1] * data->pix + OFFSET;
		i++;
	}
}

void	draw_matrice(t_fdf *data)
{
	int y;
	int x;
	printf("enter draw\n");
	data->i = 0;
	y = 0;
	while ( y <= data->height - 1)
	{
		printf("enter y while loop \n");
		x = 0;
		while(x <= data->width - 1)
		{
			printf("enter x while loop \n");
			if (data->coord[data->i][0] < data->width - 1)
			{
				printf("enter x if in draw\n");
				printf("in draw %d = [%f - %f]\n",data->i,data->crdpro[data->i][0] /*+ OFFSET*/, data->crdpro[data->i][1] /*+ OFFSET*/);
				breshenham(data->crdpro[data->i][0], data->crdpro[data->i][1], data->crdpro[data->i + 1][0], data->crdpro[data->i + 1][1],data);
				//mlx_pixel_put(data->mlx_ptr, data->win_ptr,data->crdpro[data->i][0] , data->crdpro[data->i][1] , colors(data));
			}
			if (data->coord[data->i][1] < data->height - 1)
			{
				printf("enter y if in draw\n");
				breshenham(data->crdpro[data->i][0], data->crdpro[data->i][1], data->crdpro[data->i + data->width][0], data->crdpro[data->i + data->width][1], data);
			}
			free(data->crdpro[data->i]);
			x++;
			data->i++;
		}
		y++;
	}
}

int	colors(t_fdf *data)
{
	if(data->coord[data->i][2] > 0)
		return(0x2A2787);
	else if(data->coord[data->i][2] == 0)
			return(0xF80822);
	else if(data->coord[data->i][2] < 0)
		return(0x0A7369);
	return(0);
}

void	breshenham(double x0, double y0, double x1, double y1, t_fdf *data)
{
	printf("BEGIN  breshenham 0 - [%f] [%f] --> 1 [%f][%f]\n",x0, y0, x1, y1);
	data->dx = abs((int)x1 - (int)x0);
	data->sx = x0 < x1 ? 1 : -1;
	data->dy = abs((int)y1 - (int)y0);
	data->sy = y0 < y1 ? 1 : -1;
	data->err = (data->dx > data->dy ? data->dx : -data->dy) * 0.5;
	while (x0 != x1 || y0 != y1)
	{
		printf("breshenham [%f] [%f] --> [%f] [%f]\n",x0, y0, x1, y1);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0 , y0 , colors(data));
		data->e2 = data->err;
		if (data->e2 > -data->dx)
		{
			data->err -= data->dy;
			x0 += data->sx;
		}
		if (data->e2 < data->dy)
		{
			data->err += data->dx;
			y0 += data->sy;
		}
	}
}

// void	breshenham(double x0, double y0, double x1, double y1, t_fdf *data)
// {
// 	data->dx  = abs((int)x1 - (int)x0);
// 	data->sx = x0 < x1 ? 1 : -1;
// 	data->dy = abs((int)y1 - (int)y0);
// 	data->sy = y0 < y1 ? 1 : -1;
// 	data->err = (data->dx > data->dy ? data->dx : -data->dy) * 0.5;
// 	while (x0 != x1 || y0 != y1)
// 	{
// 		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, colors(data));
// 		data->e2 = data->err;
// 		data->e2 > -data->dx ? data->err -= data->dy : 1 == 1;
// 		data->e2 > -data->dx ? x0 += data->sx : 1 == 1;
// 		data->e2 < data->dy ? data->err += data->dx : 1 == 1;
// 		data->e2 < data->dy ? y0 += data->sy : 1 == 1;
// 	}
// }
