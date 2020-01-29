/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:39:23 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/01/29 18:44:37 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		projection(_fdf *data)
{
	rotationz(data);

}

void	rotationz(t_fdf *data)
{
	int **tab;                                                                         
	data->coordpro[i][0] = (coord[i][0] * cos(0.5) + (coord[i][1] * (-sin(0.5));
	data->coordpro[i][1] = (coord[i][0] * sin(0.5) + (coord[i][2] + (cos(0.5));
	data->coordpro[i][2] = 1;

	return(tab)
}

// void	iso(t_fdf *data)
// {
//
// }
//
// void	ortho(t_fdf *data)
// {
// 	double	ortho[2][3] = {{1,0,0};{0,1,0}};
//
//
// }
