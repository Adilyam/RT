/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ua_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:43:34 by htkachuk          #+#    #+#             */
/*   Updated: 2018/06/15 17:43:36 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		yellow(t_all *ev, int xy[4])
{
	int		x;
	int		y;

	y = xy[2] - 1;
	while (++y < xy[3])
	{
		x = xy[0] - 1;
		while (++x < xy[1])
			mlx_pixel_put(ev->mlx.mlx, ev->mlx.win, x, y, 0xFFB300);
	}
}

void			re_draw_effect(t_all *ev, int i)
{
	if (i == 0)
		ev->filter = CARTOON;
	if (i == 1)
		ev->filter = SEPIA;
	if (i == 2)
		ev->filter = BLACK_WHITE;
	if (i == 3)
		ev->filter = NORMAL;
	thread(ev);
}

int				*set_array(int a, int b, int c, int d)
{
	static int		arr[4];

	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	arr[3] = d;
	return (arr);
}

void			change_effect(t_all *ev)
{
	yellow(ev, set_array(10, 150, 805, 835));
	yellow(ev, set_array(10, 150, 845, 875));
	yellow(ev, set_array(10, 150, 885, 920));
	yellow(ev, set_array(10, 150, 930, 960));
	mlx_string_put(ev->mlx.mlx, ev->mlx.win, 50, 810, 0x000000, "cartoon");
	mlx_string_put(ev->mlx.mlx, ev->mlx.win, 60, 850, 0x000000, "sepia");
	mlx_string_put(ev->mlx.mlx, ev->mlx.win, 15, 890, 0x000000,
											"black & white");
	mlx_string_put(ev->mlx.mlx, ev->mlx.win, 50, 935, 0x000000, "normal");
}
