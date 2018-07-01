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
	ev->screen = malloc(sizeof(unsigned char) * 3 * SIZE_X * SIZE_Y);
	ft_create_img(ev);
}

void		ft_put_pxl(t_all *ev, int x, int y, t_color *c)
{
	int		i;
	int		j;

	j = -1;
	while (++j < ev->k_iter)
	{
		i = (x * 4) + (y * ev->mlx.size);
		i += (4 * j);
		ev->mlx.str[i] = c->chanels.b;
		ev->mlx.str[++i] = c->chanels.g;
		ev->mlx.str[++i] = c->chanels.r;
		ev->mlx.str[++i] = 1;
		i = (x + y * SIZE_X) * 3;
		i += (3 * j);
		ev->screen[i] = c->chanels.r;
		ev->screen[++i] = c->chanels.g;
		ev->screen[++i] = c->chanels.b;
	}
}
