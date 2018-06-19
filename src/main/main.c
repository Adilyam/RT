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

int		error_end(char *str)
{
	ft_putendl(str);
	exit(0);
	return (0);
}

// static void	parsing(char *str, t_all *ev)
// {
// 	ev->vw = 1;
// 	ev->vh = 1;
// 	ev->d_d = 1;
// 	ev->func1 = NULL;
// 	if (!(ft_strcmp(str, "scene1")))
// 		ev->func1 = &define_scene1;
// 	if (!(ft_strcmp(str, "scene2")))
// 		ev->func1 = &define_scene2;
// 	if (!(ft_strcmp(str, "scene3")))
// 		ev->func1 = &define_scene3;
// 	if (!(ft_strcmp(str, "scene4")))
// 		ev->func1 = &define_scene4;
// 	if (!(ft_strcmp(str, "scene5")))
// 		ev->func1 = &define_scene5;
// 	if (!(ft_strcmp(str, "scene6")))
// 		ev->func1 = &define_scene6;
// 	if (!ev->func1)
// 	{
// 		ft_putstr_fd("usage:\t./RTv1 scene1\n", 2);
// 		ft_putstr_fd("\t./RTv1 scene2\n", 2);
// 		ft_putstr_fd("\t./RTv1 scene3\n\t./RTv1 scene4\n", 2);
// 		ft_putstr_fd("\t./RTv1 scene5\n\t./RTv1 scene6\n", 2);
// 		exit(1);
// 	}
// }

int			main(int ac, char **av)
{
	t_all		ev;

	if (ac != 2)
		error_end("usage:\t./RT scenes/[-file]");
	ev.fd = open(av[1], O_RDONLY);
	if (!parse_check(&ev))
		error_end("smth went wrong");
	// parsing(av[1], &ev);
	ft_create(&ev);
	// (ev.func1)(&ev);
	// thread(&ev);
	mlx_hook(ev.mlx.win, 4, 1L << 2, mouse_zoom, &ev);
	mlx_hook(ev.mlx.win, 2, 5, ft_key, &ev);
	mlx_hook(ev.mlx.win, 17, 1L << 17, exit_x, &ev);
	mlx_loop(ev.mlx.mlx);
	return (0);
}
