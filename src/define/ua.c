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
			mlx_pixel_put(ev->mlx.mlx, ev->mlx.win, x, y, 0xC0C0C0);
	}
}

static void		square(t_all *ev, int xy[4])
{
	int	x;
	int	y;

	y = xy[2];
	x = xy[0] - 1;
	while (++x < xy[1])
		mlx_pixel_put(ev->mlx.mlx, ev->mlx.win, x, y, 0x000000);
	y = xy[3];
	x = xy[0] - 1;
	while (++x < xy[1])
		mlx_pixel_put(ev->mlx.mlx, ev->mlx.win, x, y, 0x000000);
	y = xy[2] - 1;
	while (++y < xy[3])
		mlx_pixel_put(ev->mlx.mlx, ev->mlx.win, x, y, 0x000000);
	y = xy[2] - 1;
	x = xy[0];
	while (++y < xy[3])
		mlx_pixel_put(ev->mlx.mlx, ev->mlx.win, x, y, 0x000000);
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
	grey(ev, set_array(0, 800, 800, 1000));
	square(ev, set_array(310, 490, 835, 965));
	square(ev, set_array(375, 425, 875, 925));
	square(ev, set_array(390, 410, 890, 910));
	square(ev, set_array(460, 480, 845, 855));
	square(ev, set_array(465, 475, 815, 835));
	black(ev, set_array(309, 491, 834, 966));
	white_m(ev, set_array(310, 490, 835, 965));
	black(ev, set_array(310, 490, 835, 870));
	grey(ev, set_array(465, 480, 845, 855));
	black(ev, set_array(375, 425, 875, 925));
	grey(ev, set_array(390, 410, 890, 910));
	change_effect(ev);
}
