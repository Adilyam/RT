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
		m = multy_vec(d, vector_multy_const(ev->figure[i].point, closet_t));
		m += multy_vec(oc, ev->figure[i].point);
		ev->n = vector_minus_vector(ev->p, ev->figure[i].centre);
		ev->n = vector_minus_vector(ev->n,
		vector_multy_const(ev->figure[i].point, (m + ev->figure[i].k)));
	}
	else if (ev->figure[i].id_figure == ELLIPSOID)
	{
		ev->figure[i].point = normalise(ev->figure[i].point);
		oc = vector_minus_vector(o, ev->figure[i].centre);
		cmid = vector_plus_vector(ev->figure[i].centre, vector_multy_const(ev->figure[i].point, ev->figure[i].k / 2));
		r = vector_minus_vector(ev->p, cmid);
		ev->n = vector_minus_vector(r, vector_multy_const(ev->figure[i].point, (1 - (pow(ev->a, 2) / pow(ev->b, 2))) * multy_vec(r, ev->figure[i].point)));
		ev->n = normalise(ev->n);
		// printf("why");
	}
}

static void	figure_type_1(int i, t_all *ev, double closet_t, t_vector o, t_vector d)
{
	double		m;
	t_vector	oc;
 
	if (ev->figure[i].id_figure == CYLINDRE || ev->figure[i].id_figure == CYLINDRE_CUT)
	{
		oc = vector_minus_vector(o, ev->figure[i].centre);
		m = multy_vec(d, vector_multy_const(ev->figure[i].point, closet_t));
		m += multy_vec(oc, ev->figure[i].point);
		ev->n = vector_minus_vector(ev->p, ev->figure[i].centre);
		ev->n = vector_minus_vector(ev->n,
			vector_multy_const(ev->figure[i].point, m));
	}
	else if (ev->figure[i].id_figure == CONE || ev->figure[i].id_figure == CONE_CUT)
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

void	figure_type_other(int i, t_all *ev, double closet_t, t_vector o, t_vector d)
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
	else if (ev->figure[i].id_figure == ELLIPSOID || ev->figure[i].id_figure == PARABOLOID)
 		 figure_type_2(i, ev, closet_t, o, d);
	else if (ev->figure[i].id_figure == CYLINDRE || 
			ev->figure[i].id_figure == CONE ||
			ev->figure[i].id_figure == CYLINDRE_CUT)
		figure_type_1(i, ev, closet_t, o, d);
}

static void figure_type(int i, t_all *ev)
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

double		closet_interesection(t_all *ev, double *t, t_vector o, t_vector d)
{
	int		i;
	double	closet_t;

	closet_t = t[1];
	ev->id = -1;
	i = -1;
	while (++i < ev->num_f)
	{
		figure_type(ev->figure[i].id_figure, ev);
		(ev->inter)(ev, i, o, d);
		if (ev->x1 >= t[0] && ev->x1 <= t[1] && ev->x1 < closet_t)
		{
			ev->id = i;
			closet_t = ev->x1;
		}
		if (ev->x2 >= t[0] && ev->x2 <= t[1] && ev->x2 < closet_t)
		{
			ev->id = i;
			closet_t = ev->x2;
		}
	}
	return (closet_t);
}

t_vector	rotate_vec_y(t_vector *v, t_vector *rot)
{
	t_vector	res;
	double		deg;

	deg = rot->y * PIOVER180;
	res.x = v->x * cos(deg) + sin(deg) * v->z;
	res.y = v->y;
	res.z = -v->x * sin(deg) + v->z * cos(deg);
	return (res);
}

t_vector	rotate_vec_z(t_vector *v, t_vector *rot)
{
	t_vector	res;
	double		deg;

	deg = rot->z * PIOVER180;
	res.x = v->x * cos(deg) + sin(deg) * v->y;
	res.y = -v->x * sin(deg) + cos(deg) * v->y;
	res.z = v->z;
	return (res);
}

t_vector	rotate_vec_x(t_vector *v, t_vector *rot)
{
	t_vector	res;
	double		deg;

	deg = rot->x * PIOVER180;
	res.x = v->x;
	res.y = v->y * cos(deg) + v->z * sin(deg);
	res.z = -v->y * sin(deg) + v->z * cos(deg);
	return (res);
}

void		rot_figure(t_all *ev)
{
	if (ev->o_rot.x != 0)
		ev->d = rotate_vec_x(&ev->d, &ev->o_rot);
	if (ev->o_rot.y != 0)
		ev->d = rotate_vec_y(&ev->d, &ev->o_rot);
	if (ev->o_rot.z != 0)
		ev->d = rotate_vec_z(&ev->d, &ev->o_rot);
}

