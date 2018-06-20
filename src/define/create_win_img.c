/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:11:50 by htkachuk          #+#    #+#             */
/*   Updated: 2018/05/04 12:11:52 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	ft_create_img(t_all *ev)
{
	ev->mlx.bits = sizeof(int) * 8;
	ev->mlx.size = sizeof(int) * SIZE_X;
	ev->mlx.end = 0;
	ev->mlx.img = mlx_new_image(ev->mlx.mlx, SIZE_X, SIZE_Y);
	ev->mlx.str = mlx_get_data_addr(ev->mlx.img, &(ev->mlx.bits),
		&(ev->mlx.size), &(ev->mlx.end));
}

void		ft_create(t_all *ev)
{
	ev->mlx.mlx = mlx_init();
	ev->mlx.win = mlx_new_window(ev->mlx.mlx, SIZE_X, SIZE_Y_WIN, "RT");
	ft_create_img(ev);
}
