/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 19:15:40 by htkachuk          #+#    #+#             */
/*   Updated: 2018/05/21 19:15:42 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		figure_type_2(int i, t_all *ev, t_vector o, t_vector d)
{
	double		m;
	t_vector	v[3];

	if (ev->figure[i].id_figure == PARABOLOID)
	{
		v[0] = vector_minus_vector(o, ev->figure[i].centre);
		m = multy_vec(vector_minus_vector(ev->p, ev->figure[i].centre),
											ev->figure[i].point);
		m = multy_vec(d, vector_multy_const(ev->figure[i].point, ev->closet_t));
		m += multy_vec(v[0], ev->figure[i].point);
		ev->n = vector_minus_vector(ev->p, ev->figure[i].centre);
		ev->n = vector_minus_vector(ev->n,
		vector_multy_const(ev->figure[i].point, (m + ev->figure[i].k)));
	}
	else if (ev->figure[i].id_figure == ELLIPSOID)
	{
		v[1] = vector_plus_vector(ev->figure[i].centre,
				vector_multy_const(ev->figure[i].point, ev->figure[i].k / 2));
		v[2] = vector_minus_vector(ev->p, v[1]);
		ev->n = vector_minus_vector(v[2], vector_multy_const(
				ev->figure[i].point, (1 - (pow(ev->a, 2) / pow(ev->b, 2))) *
				multy_vec(v[2], ev->figure[i].point)));
		ev->n = normalise(ev->n);
	}
}

static void		figure_type_1(int i, t_all *ev, t_vector o, t_vector d)
{
	double		m;
	t_vector	oc;

	if (ev->figure[i].id_figure == CYLINDRE ||
		ev->figure[i].id_figure == CYLINDRE_CUT)
	{
		oc = vector_minus_vector(o, ev->figure[i].centre);
		m = multy_vec(d, vector_multy_const(ev->figure[i].point, ev->closet_t));
		m += multy_vec(oc, ev->figure[i].point);
		ev->n = vector_minus_vector(ev->p, ev->figure[i].centre);
		ev->n = vector_minus_vector(ev->n,
			vector_multy_const(ev->figure[i].point, m));
	}
	else if (ev->figure[i].id_figure == CONE ||
			ev->figure[i].id_figure == CONE_CUT)
	{
		oc = vector_minus_vector(o, ev->figure[i].centre);
		m = multy_vec(d, vector_multy_const(ev->figure[i].point, ev->closet_t));
		m += multy_vec(oc, ev->figure[i].point);
		ev->n = vector_minus_vector(ev->p, ev->figure[i].centre);
		ev->n = vector_minus_vector(ev->n,
			vector_multy_const(ev->figure[i].point,
				(m * (1 + pow(ev->figure[i].radius, 2)))));
	}
}

void			figure_type_other(int i, t_all *ev, t_vector o, t_vector d)
{
	if (ev->figure[i].id_figure == SPHERE)
		ev->n = vector_minus_vector(ev->p, ev->figure[i].centre);
	else if (ev->figure[i].id_figure == PLANE)
	{
		if (multy_vec(d, ev->figure[i].point) > 0)
			ev->n = define_vector(-ev->figure[i].centre.x,
			-ev->figure[i].centre.y, -ev->figure[i].centre.z);
		else
			ev->n = ev->figure[i].centre;
	}
	else if (ev->figure[i].id_figure == ELLIPSOID ||
			ev->figure[i].id_figure == PARABOLOID)
		figure_type_2(i, ev, o, d);
	else if (ev->figure[i].id_figure == CYLINDRE ||
			ev->figure[i].id_figure == CONE ||
			ev->figure[i].id_figure == CYLINDRE_CUT)
		figure_type_1(i, ev, o, d);
}

static void		figure_type(int i, t_all *ev)
{
	if (i == SPHERE)
		ev->inter = &intersect_ray_sphere;
	else if (i == PLANE)
		ev->inter = &intersect_ray_plane;
	else if (i == CYLINDRE || i == CYLINDRE_CUT)
		ev->inter = &intersect_ray_cylinder;
	else if (i == CONE || i == CONE_CUT)
		ev->inter = &intersect_ray_cone;
	else if (i == ELLIPSOID)
		ev->inter = &intersect_ray_elips;
	else if (i == PARABOLOID || i == PARABOLOID_CUT)
		ev->inter = &intersect_ray_par;
}

double			closet_interesection(t_all *ev, double *t, t_vector o,
										t_vector d)
{
	int		i;

	ev->closet_t = t[1];
	ev->id = -1;
	i = -1;
	while (++i < ev->num_f)
	{
		figure_type(ev->figure[i].id_figure, ev);
		(ev->inter)(ev, i, o, d);
		if (ev->x1 >= t[0] && ev->x1 <= t[1] && ev->x1 < ev->closet_t)
		{
			ev->id = i;
			ev->closet_t = ev->x1;
		}
		if (ev->x2 >= t[0] && ev->x2 <= t[1] && ev->x2 < ev->closet_t)
		{
			ev->id = i;
			ev->closet_t = ev->x2;
		}
	}
	return (ev->closet_t);
}
