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

#include "rtv1.h"

static void	figure_type_1(int i, t_all *ev, double closet_t)
{
	double		m;
	t_vector	oc;

	if (ev->figure[i].id_figure == 2)
	{
		oc = vector_minus_vector(ev->o, ev->figure[i].centre);
		m = multy_vec(ev->d, vector_multy_const(ev->figure[i].point, closet_t));
		m += multy_vec(oc, ev->figure[i].point);
		ev->n = vector_minus_vector(ev->p, ev->figure[i].centre);
		ev->n = vector_minus_vector(ev->n,
			vector_multy_const(ev->figure[i].point, m));
	}
	if (ev->figure[i].id_figure == 3)
	{
		oc = vector_minus_vector(ev->o, ev->figure[i].centre);
		m = multy_vec(ev->d, vector_multy_const(ev->figure[i].point, closet_t));
		m += multy_vec(oc, ev->figure[i].point);
		ev->n = vector_minus_vector(ev->p, ev->figure[i].centre);
		ev->n = vector_minus_vector(ev->n,
			vector_multy_const(ev->figure[i].point,
				(m * (1 + pow(ev->figure[i].radius, 2)))));
	}
}

static void	figure_type(int i, t_all *ev, double closet_t)
{
	if (ev->figure[i].id_figure == 0)
		ev->n = vector_minus_vector(ev->p, ev->figure[i].centre);
	if (ev->figure[i].id_figure == 1)
	{
		if (multy_vec(ev->d, ev->figure[i].centre) > 0)
			ev->n = define_vector(-ev->figure[i].centre.x,
				-ev->figure[i].centre.y, -ev->figure[i].centre.z);
		else
			ev->n = vector_minus_vector(ev->p, ev->figure[i].point);
	}
	if (ev->figure[i].id_figure == 2 || ev->figure[i].id_figure == 3)
		figure_type_1(i, ev, closet_t);
}

static void	use_light(t_all *ev, double closet_t, int i)
{
	double	j;

	ev->v = define_vector(0 - (ev->d.x), 0 - (ev->d.y), (0 - ev->d.z));
	ev->v = normalise(ev->v);
	ev->p = vector_plus_vector(ev->o, (vector_multy_const(ev->d, closet_t)));
	figure_type(i, ev, closet_t);
	ev->n = normalise(ev->n);
	j = compute_lighting(ev, i);
	ev->color = multy_col(ev->figure[i].color, j);
}

static void	trace_ray(t_all *ev)
{
	double	closet_t;
	double	t[2];

	t[0] = 0.01f;
	t[1] = MAX;
	closet_t = closet_interesection(ev, t, ev->o, ev->d);
	if (ev->id == -1)
	{
		ev->color = 0x000000;
		return ;
	}
	use_light(ev, closet_t, ev->id);
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
			ev->d.x = ((x - SIZE_X / 2) * (ev->vw / SIZE_X / 2));
			ev->d.y = (-(y - SIZE_Y / 2) * (ev->vh / SIZE_Y / 2));
			ev->d.z = ev->d_d;
			ev->d = normalise(ev->d);
			rot_figure(ev);
			trace_ray(ev);
			*(unsigned int *)(ev->mlx.str + (((x)
			+ (y) * SIZE_Y) * 4)) = ev->color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(ev->mlx.mlx, ev->mlx.win, ev->mlx.img, 0, 0);
}
