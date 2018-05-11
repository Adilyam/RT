/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:03:41 by htkachuk          #+#    #+#             */
/*   Updated: 2018/05/04 12:03:49 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

static int	exit_x(void)
{
	exit(0);
}

int	main(void)
{
	t_all	ev;

	ft_create(&ev);
	define(&ev);
	define_light(&ev);
	draw_scene(&ev);
	mlx_hook(ev.mlx.win, 2, 5, ft_key, &ev);
	mlx_hook(ev.mlx.win, 17, 1L << 17, exit_x, &ev);
	mlx_loop(ev.mlx.mlx);
	return (0);
}
