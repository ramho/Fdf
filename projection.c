/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:28:20 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/01/24 14:42:43 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	iso_x(int x, int y)
{
	int x1;

	x1= (x - y) * cos(0.5);
	printf("x1 in iso %d\n", x1);
	return(x1);
}

int	iso_y(int x,int y, int z)
{
	int y1;
	printf("z = %d\n", z);
	y1= (x + y) * sin(0.5) - z;
	return(y1);
}

/*int 	orthographic(t_fdf *data)
{
	x` = x;
	y` = y;
}*/

/*int		perspective(t_fdf *data)
{
	x`=
	y`=
}*/
