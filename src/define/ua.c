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

static void	grey(t_all *ev, int x_min, int x_max, int y_min, int y_max)
{
	int		x;
	int		y;


	y = y_min - 1;
	while (++y < y_max)
	{
		x = x_min - 1;
		while (++x < x_max)
			mlx_pixel_put(ev->mlx.mlx, ev->mlx.win, x, y, 0xFFFFFF);
	}
}

static void	white_m(t_all *ev, int x_min, int x_max, int y_min, int y_max)
{
	int		x;
	int		y;


	y = y_min - 1;
	while (++y < y_max)
	{
		x = x_min - 1;
		while (++x < x_max)
			mlx_pixel_put(ev->mlx.mlx, ev->mlx.win, x, y, 0xC0C0C0);
	}
}

static void square(t_all *ev, int x_min, int y_min, int x_max, int y_max)
{
	int	x;
	int	y;

	y = y_min;
	x = x_min - 1;
	while (++x < x_max)
		mlx_pixel_put(ev->mlx.mlx, ev->mlx.win, x, y, 0x000000);
	y = y_max;
	x = x_min - 1;
	while (++x < x_max)
		mlx_pixel_put(ev->mlx.mlx, ev->mlx.win, x, y, 0x000000);
	y = y_min - 1;
	while (++y < y_max)
		mlx_pixel_put(ev->mlx.mlx, ev->mlx.win, x, y, 0x000000);
	y = y_min - 1;
	x = x_min;
	while (++y < y_max)
		mlx_pixel_put(ev->mlx.mlx, ev->mlx.win, x, y, 0x000000);

}

static void	black(t_all *ev, int x_min, int x_max, int y_min, int y_max)
{
	int		x;
	int		y;

	y = y_min - 1;
	while (++y < y_max)
	{
		x = x_min - 1;
		while (++x < x_max)
			mlx_pixel_put(ev->mlx.mlx, ev->mlx.win, x, y, 0x000000);
	}
}

void	make_screenshot(t_all *ev)
{
	grey(ev, 0, 800, 800, 1000);
	square(ev, 310, 835, 490, 965);
	square(ev, 375, 875, 425, 925);
	square(ev, 390, 890, 410, 910);
	square(ev, 460, 845, 480, 855);
	square(ev, 465, 815, 475, 835);
	black(ev, 309, 491, 834, 966);
	white_m(ev, 310, 490, 835, 965);
	black(ev, 310, 490, 835, 870);
	grey(ev, 465, 480, 845, 855);
	black(ev, 375, 425, 875, 925);
	grey(ev, 390, 410, 890, 910);
	change_effect(ev);
}
