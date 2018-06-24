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

#include "rt.h"
#include <sys/types.h>
#include <sys/stat.h>

static int	exit_x(void)
{
	exit(0);
}

int		error_end(char *str)
{
	ft_putendl(str);
	exit(0);
}

void		start(t_all *ev, char **av)
{
	ev->fd = open(av[1], O_RDONLY);
	struct stat buf;
    stat(av[1],&buf);
	if(S_ISDIR(buf.st_mode))
  		error_end("This is a directory");
	if (ev->fd <= 0)
		error_end("Such file doesn't exist");
	ev->vw = 1;
	ev->vh = 1;
	ev->d_d = 1;
	ev->k_iter = 1;
	ev->filter = NORMAL;
	ev->o = define_vector(0, 0, 0);
	ev->o_rot = define_vector(0, 0, 0);
	if (!parse_check(ev))
		error_end("The scene is not JSON formatted");
	normalise_obj(ev);
	ft_create(ev);
	make_screenshot(ev);
	thread(ev);
	mlx_hook(ev->mlx.win, 4, 1L << 2, mouse_zoom, ev);
	mlx_hook(ev->mlx.win, 2, 5, ft_key, ev);
	mlx_hook(ev->mlx.win, 17, 1L << 17, exit_x, ev);
	mlx_loop(ev->mlx.mlx);
}

int			main(int ac, char **av)
{
	t_all		ev;

	if (ac != 2)
		error_end("usage:\t./RT scenes/[-file]");
	start(&ev, av);
	return (0);
}
