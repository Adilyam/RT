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

#include "rt.h"

static void figure_type_2(int i, t_all *ev, double closet_t, t_vector o, t_vector d)
{
	double  m;
	t_vector oc;
	t_vector	cmid;
	t_vector	r;

	if (ev->figure[i].id_figure == PARABOLOID)
	{
		oc = vector_minus_vector(o, ev->figure[i].centre);
		m = multy_vec(vector_minus_vector(ev->p, ev->figure[i].centre), ev->figure[i].point);
		// m = multy_vec(d, vector_multy_const(ev->figure[i].point, closet_t));
		// m += multy_vec(oc, ev->figure[i].point);
		ev->n = vector_minus_vector(ev->p, ev->figure[i].centre);
		ev->n = vector_minus_vector(ev->n,
		vector_multy_const(ev->figure[i].point, (m + ev->figure[i].k)));
	}
	if (ev->figure[i].id_figure == ELLIPSOID)
	{
		ev->figure[i].point = normalise(ev->figure[i].point);
		oc = vector_minus_vector(o, ev->figure[i].centre);
		cmid = vector_plus_vector(ev->figure[i].centre, vector_multy_const(ev->figure[i].point, ev->figure[i].k / 2));
		r = vector_minus_vector(ev->p, cmid);
		ev->n = vector_minus_vector(r, vector_multy_const(ev->figure[i].point, (1 - (pow(ev->a, 2) / pow(ev->b, 2))) * multy_vec(r, ev->figure[i].point)));
		ev->n = normalise(ev->n);
	}
}

static void	figure_type_1(int i, t_all *ev, double closet_t, t_vector o, t_vector d)
{
	double		m;
	t_vector	oc;

	if (ev->figure[i].id_figure == CYLINDRE)
	{
		oc = vector_minus_vector(o, ev->figure[i].centre);
		m = multy_vec(d, vector_multy_const(ev->figure[i].point, closet_t));
		m += multy_vec(oc, ev->figure[i].point);
		ev->n = vector_minus_vector(ev->p, ev->figure[i].centre);
		ev->n = vector_minus_vector(ev->n,
			vector_multy_const(ev->figure[i].point, m));
	}
	if (ev->figure[i].id_figure == CONE)
	{
		oc = vector_minus_vector(o, ev->figure[i].centre);
		m = multy_vec(d, vector_multy_const(ev->figure[i].point, closet_t));
		m += multy_vec(oc, ev->figure[i].point);
		ev->n = vector_minus_vector(ev->p, ev->figure[i].centre);
		ev->n = vector_minus_vector(ev->n,
			vector_multy_const(ev->figure[i].point,
				(m * (1 + pow(ev->figure[i].radius, 2)))));
	}
}

static void	figure_type(int i, t_all *ev, double closet_t, t_vector o, t_vector d)
{
	if (ev->figure[i].id_figure == SPHERE)
		ev->n = vector_minus_vector(ev->p, ev->figure[i].centre);
	if (ev->figure[i].id_figure == PLANE)
	{
		if (multy_vec(d, ev->figure[i].point) > 0)
			ev->n = define_vector(-ev->figure[i].centre.x,
			-ev->figure[i].centre.y, -ev->figure[i].centre.z);
		else
			ev->n = ev->figure[i].centre;
	}
	if (ev->figure[i].id_figure == ELLIPSOID || ev->figure[i].id_figure == PARABOLOID)
 		 figure_type_2(i, ev, closet_t, o, d);
	if (ev->figure[i].id_figure == CYLINDRE || ev->figure[i].id_figure == CONE)
		figure_type_1(i, ev, closet_t, o, d);
}

static t_color	use_light(t_all *ev, double closet_t, int i, t_vector o, t_vector d)
{
	double	j;
	t_color	color;

	ev->v = define_vector(0 - (d.x), 0 - (d.y), (0 - d.z));
	ev->v = normalise(ev->v);
	ev->p = vector_plus_vector(o, (vector_multy_const(d, closet_t)));
	figure_type(i, ev, closet_t, o, d);
	ev->n = normalise(ev->n);
	j = compute_lighting(ev, i);
	color = multy_col(ev->figure[i].color, j);
	return (color);
}

// #include <stdio.h>
t_vector reflect_ray(t_vector r, t_vector n)
{
	t_vector	k;
	double		n_dot_r;

	n_dot_r = multy_vec(r, n);
	k = vector_multy_const(n, (2.0 * n_dot_r));
	k =  vector_minus_vector(k, r);
	k = normalise(k);
	return (k);
}

#include <stdio.h>

static t_color	trace_ray(t_all *ev, t_vector o, t_vector d, int depth, int i)
{
	double		closet_t;
	double		t[2];
	t_color		local_color;
	t_color		reflected_color;
	double		r;
	t_vector	rr;

	t[0] = 0.001f;
	if (i)
		t[0] = 1;
	t[1] = MAX;
	closet_t = closet_interesection(ev, t, o, d);
	if (ev->id == -1)
	{
		local_color.color = 0x000000;
		return (local_color);
	}
	local_color = use_light(ev, closet_t, ev->id, o, d);
	r = ev->figure[ev->id].reflect;
	if (depth <= 0 || r <= 0)
	{
		ev->color = local_color.color;
		return (local_color);
	}
	rr =  reflect_ray(vector_multy_const(d, -1), ev->n);
	reflected_color = trace_ray(ev, ev->p, ev->r, depth - 1, 0);
	return (color_ret(local_color, reflected_color, r));
}

void		*draw_scene(void *data)
{
	t_color	color;
	t_all	*ev;
	double	tmp;

	ev = data;
	tmp = ev->y;
	ev->x = 0;
	while (ev->x < SIZE_X)
	{
		ev->y = tmp;
		while (ev->y < ev->limit)
		{
			ev->d.x = ((ev->x - SIZE_X / 2) * (ev->vw / SIZE_X / 2));
			ev->d.y = (-(ev->y - SIZE_Y / 2) * (ev->vh / SIZE_Y / 2));
			ev->d.z = ev->d_d;
			ev->d = normalise(ev->d);
			rot_figure(ev);
			color = trace_ray(ev, ev->o, ev->d, 5, 1);
			// (ev->filter == CARTOON) ? make_cartoon(&color) : 0;
			// (ev->filter == SEPIA) ? make_sepia(&color) : 0;
			// (ev->filter == BLACK_WHITE) ? make_black_white(&color) : 0;
			*(unsigned int *)(ev->mlx.str + (((ev->x)
			+ (ev->y) * SIZE_Y) * 4)) = color.color;
			ev->y++;
		}
		ev->x++;
	}
	pthread_exit(0);
}

void	thread(t_all *e)
{
	pthread_t	tid[20];
	t_all		env_arr[20];
	int i;

	i = 0;
	while (i < 20)
	{
		env_arr[i] = *e;
		env_arr[i].y = 40 * i;
		env_arr[i].limit = 40 * (i + 1);
		i++;
	}
	i = 0;
	while (++i <= 20)
		pthread_create(&tid[i - 1], NULL, draw_scene, &env_arr[i - 1]);
	while (i--)
		pthread_join(tid[i], NULL);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
}
