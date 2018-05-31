/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:33:32 by htkachuk          #+#    #+#             */
/*   Updated: 2018/05/04 12:33:35 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

static void	canvas_to_viewpoint(double x, double y, t_all *ev)
{
	ev->d.x = ((x - SIZE_X / 2) * (ev->Vw / SIZE_X) - ev->o.x);
	ev->d.y = (-(y - SIZE_Y / 2) * (ev->Vh / SIZE_Y) - ev->o.y);
	ev->d.z = ev->d_d;
	ev->d = normalise(ev->d);
}

static void	use_light(t_all *ev, double closet_t, int i)
{
	double	j;
	int		k;

	k = 0;
	ev->v = define_vector(0 - (ev->d.x), 0 - (ev->d.y), (0 - ev->d.z));
	ev->v = normalise(ev->v);
	ev->p = vector_plus_vector(ev->o, (vector_multy_const(ev->d, closet_t)));
	ev->n = vector_minus_vector(ev->p, ev->sphere[i].centre);
	ev->n = normalise(ev->n);
	j = compute_lighting(ev, i);
	ev->color = multy_col(ev->sphere[i].color, j);
}

static void	trace_ray(t_all *ev)
{
	double	closet_t;

	closet_t = closet_interesection(ev, MIN, ev->o, ev->d);
	if (ev->id_sph == -1)
	{
		ev->color = 0xFFFFFF;
		return ;
	}
	use_light(ev, closet_t, ev->id_sph);
}

void		draw_scene(t_all *ev)
{
	int	x;
	int	y;

	y = 0;
	while (y < SIZE_Y)
	{
		x = 0;
		while (x < SIZE_X)
		{
			canvas_to_viewpoint((double)x, (double)y, ev);
			trace_ray(ev);
			*(unsigned int *)(ev->mlx.str + (((x)
			+ (y) * SIZE_Y) * 4)) = ev->color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(ev->mlx.mlx, ev->mlx.win, ev->mlx.img, 0, 0);
}
