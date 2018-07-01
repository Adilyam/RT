/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ua.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 18:33:15 by htkachuk          #+#    #+#             */
/*   Updated: 2018/06/18 18:33:17 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		grey(t_all *ev, int xy[4])
{
	int		x;
	int		y;

	y = xy[2] - 1;
	while (++y < xy[3])
	{
		x = xy[0] - 1;
		while (++x < xy[1])
			mlx_pixel_put(ev->mlx.mlx, ev->mlx.win, x, y, 0xFFFFFF);
	}
}

static void		white_m(t_all *ev, int xy[4])
{
	int		x;
	int		y;

	y = xy[2] - 1;
	while (++y < xy[3])
	{
		x = xy[0] - 1;
		while (++x < xy[1])
			mlx_pixel_put(ev->mlx.mlx, ev->mlx.win, x, y, 0xedecd7);
	}
}

static void		black(t_all *ev, int xy[4])
{
	int		x;
	int		y;

	y = xy[2] - 1;
	while (++y < xy[3])
	{
		x = xy[0] - 1;
		while (++x < xy[1])
			mlx_pixel_put(ev->mlx.mlx, ev->mlx.win, x, y, 0x000000);
	}
}

void			make_screenshot(t_all *ev)
{
	grey(ev, set_array(0, 1000, 800, 850));
	black(ev, set_array(495, 535, 813, 840));
	white_m(ev, set_array(512, 518, 822, 827));
	black(ev, set_array(495, 535, 810, 812));
	change_effect(ev);
}
