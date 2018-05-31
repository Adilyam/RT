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

int	main(int ac, char **av)
{
	t_all	ev;

	if (ac != 2)
	{
		ft_putstr_fd("usage:\t./RTv1 scene\n", 2);
		av[1] = "fuck";
		return (0);
	}
	// open_read(&ev, av[1]);
	ft_create(&ev);
	define(&ev);
	define_light(&ev);
	draw_scene(&ev);
	mlx_hook(ev.mlx.win, 2, 5, ft_key, &ev);
	mlx_hook(ev.mlx.win, 17, 1L << 17, exit_x, &ev);
	mlx_loop(ev.mlx.mlx);
	return (0);
}
