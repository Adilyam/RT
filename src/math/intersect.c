/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:20:43 by htkachuk          #+#    #+#             */
/*   Updated: 2018/05/31 17:20:46 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		intersect_ray_sphere(t_all *ev, int i, t_vector o, t_vector d)
{
	t_vector	oc;
	double		k[3];

	oc = vector_minus_vector(o, ev->figure[i].centre);
	k[0] = multy_vec(d, d);
	k[1] = 2 * (multy_vec(d, oc));
	k[2] = (multy_vec(oc, oc)) - (pow(ev->figure[i].radius, 2));
	discr(ev, k);
}

void		intersect_ray_plane(t_all *ev, int i, t_vector o, t_vector d)
{
	t_vector	x;
	t_vector	c;
	t_vector	n;
	float		k[2];

	c = ev->figure[i].point;
	n = ev->figure[i].centre;
	n = normalise(n);
	x = vector_minus_vector(o, c);
	k[0] = multy_vec(d, n);
	k[1] = multy_vec(x, n);
	ev->x1 = -k[1] / k[0];
	if (ev->x1 > 0.01)
		ev->x2 = MAX;
	else
	{
		ev->x1 = MAX;
		ev->x2 = MAX;
	}
}

void		intersect_ray_cylinder(t_all *ev, int i, t_vector o, t_vector d)
{
	t_vector	oc;
	double		k[3];

	oc = vector_minus_vector(o, ev->figure[i].centre);
	k[0] = multy_vec(d, d);
	k[0] -= pow((multy_vec(d, ev->figure[i].point)), 2);
	k[1] = multy_vec(oc, d);
	k[1] -= (multy_vec(d, ev->figure[i].point) *
		multy_vec(oc, ev->figure[i].point));
	k[1] = 2 * k[1];
	k[2] = (multy_vec(oc, oc));
	k[2] -= pow(multy_vec(oc, ev->figure[i].point), 2);
	k[2] -= pow(ev->figure[0].radius, 2);
	discr(ev, k);
	if (ev->figure[i].id_figure == CYLINDRE_CUT)
		cut_cylinder(ev, i, d, oc);
}

void		intersect_ray_cone(t_all *ev, int i, t_vector o, t_vector d)
{
	t_vector	oc;
	double		k[3];

	oc = vector_minus_vector(o, ev->figure[i].centre);
	k[0] = multy_vec(d, d) - (1 + pow(ev->figure[i].radius, 2))
	* pow((multy_vec(d, ev->figure[i].point)), 2);
	k[1] = multy_vec(oc, d);
	k[1] -= (1 + pow(ev->figure[i].radius, 2))
	* (multy_vec(d, ev->figure[i].point) * multy_vec(oc, ev->figure[i].point));
	k[1] = 2 * k[1];
	k[2] = (multy_vec(oc, oc));
	k[2] -= (1 + pow(ev->figure[i].radius, 2))
	* pow(multy_vec(oc, ev->figure[i].point), 2);
	discr(ev, k);
	if (ev->figure[i].id_figure == CONE_CUT)
		cut_cylinder(ev, i, d, oc);
}
