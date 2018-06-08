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

#include "rtv1.h"

static int	exit_x(void)
{
	exit(0);
}

int			main(int ac, char **av)
{
	t_all		ev;

	if (ac != 2)
	{
		ft_putstr_fd("usage:\t./RTv1 scene1\n", 2);
		ft_putstr_fd("\t./RTv1 scene2\n", 2);
		ft_putstr_fd("\t./RTv1 scene3\n\t", 2);
		ft_putstr_fd("./RTv1 scene4\n\t./RTv1 scene5\n", 2);
		return (1);
	}
	parsing(av[1], &ev);
	ft_create(&ev);
	(ev.func1)(&ev);
	draw_scene(&ev);
	mlx_hook(ev.mlx.win, 4, 1L << 2, mouse_zoom, &ev);
	mlx_hook(ev.mlx.win, 2, 5, ft_key, &ev);
	mlx_hook(ev.mlx.win, 17, 1L << 17, exit_x, &ev);
	mlx_loop(ev.mlx.mlx);
	return (0);
}
