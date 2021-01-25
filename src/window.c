/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <rhoorntj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:56:37 by rhoorntj          #+#    #+#             */
/*   Updated: 2020/02/17 13:51:23 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		close_win(void *param)
{
	t_fdf	*data;

	data = (t_fdf *)param;
	free_data(data);
	exit(1);
}

void	set_hooks(t_fdf *data)
{
	mlx_hook(data->win_ptr, 17, 0, close_win, data);
}
