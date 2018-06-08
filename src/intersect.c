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

#include "rtv1.h"

void	intersect_ray_sphere(t_all *ev, int i, t_vector o, t_vector d)
{
	t_vector	oc;
	double		k1;
	double		k2;
	double		k3;
	double		discriminant;

	oc = vector_minus_vector(o, ev->figure[i].centre);
	k1 = multy_vec(d, d);
	k2 = 2 * (multy_vec(d, oc));
	k3 = (multy_vec(oc, oc)) - (pow(ev->figure[i].radius, 2));
	discriminant = (pow(k2, 2)) - (4 * k1 * k3);
	if (discriminant < 0)
	{
		ev->x1 = MAX;
		ev->x2 = MAX;
		return ;
	}
	ev->x1 = (-k2 + sqrt(discriminant)) / (2 * k1);
	ev->x2 = (-k2 - sqrt(discriminant)) / (2 * k1);
}

void	intersect_ray_plane(t_all *ev, int i, t_vector o, t_vector d)
{
	double		a;
	t_vector	oc;
	double		b;
	t_vector	x;

	b = multy_vec(d, ev->figure[i].centre);
	if (b != 0)
	{
		oc = vector_minus_vector(o, ev->figure[i].point);
		x = define_vector(-oc.x, -oc.y, -oc.z);
		a = multy_vec(x, ev->figure[i].centre);
		ev->x1 = a / b;
		if (ev->x1 < 0.001f)
			ev->x1 = MAX;
	}
	ev->x2 = MAX;
}

void	intersect_ray_cylinder(t_all *ev, int i, t_vector o, t_vector d)
{
	t_vector	oc;
	double		k1;
	double		k2;
	double		k3;
	double		discriminant;

	oc = vector_minus_vector(o, ev->figure[i].centre);
	k1 = multy_vec(d, d);
	k1 -= pow((multy_vec(d, ev->figure[i].point)), 2);
	k2 = multy_vec(oc, d);
	k2 -= (multy_vec(d, ev->figure[i].point) *
		multy_vec(oc, ev->figure[i].point));
	k2 = 2 * k2;
	k3 = (multy_vec(oc, oc));
	k3 -= pow(multy_vec(oc, ev->figure[i].point), 2);
	k3 -= pow(ev->figure[0].radius, 2);
	discriminant = (pow(k2, 2)) - (4 * k1 * k3);
	if (discriminant < 0)
	{
		ev->x1 = MAX;
		ev->x2 = MAX;
		return ;
	}
	ev->x1 = (-k2 + sqrt(discriminant)) / (2 * k1);
	ev->x2 = (-k2 - sqrt(discriminant)) / (2 * k1);
}

void	intersect_ray_cone(t_all *ev, int i, t_vector o, t_vector d)
{
	t_vector	oc;
	double		k1;
	double		k2;
	double		k3;
	double		discriminant;

	oc = vector_minus_vector(o, ev->figure[i].centre);
	k1 = multy_vec(d, d) - (1 + pow(ev->figure[i].radius, 2))
	* pow((multy_vec(d, ev->figure[i].point)), 2);
	k2 = multy_vec(oc, d);
	k2 -= (1 + pow(ev->figure[i].radius, 2))
	* (multy_vec(d, ev->figure[i].point) * multy_vec(oc, ev->figure[i].point));
	k2 = 2 * k2;
	k3 = (multy_vec(oc, oc));
	k3 -= (1 + pow(ev->figure[i].radius, 2))
	* pow(multy_vec(oc, ev->figure[i].point), 2);
	discriminant = (pow(k2, 2)) - (4 * k1 * k3);
	if (discriminant < 0)
	{
		ev->x1 = MAX;
		ev->x2 = MAX;
		return ;
	}
	ev->x1 = (-k2 + sqrt(discriminant)) / (2 * k1);
	ev->x2 = (-k2 - sqrt(discriminant)) / (2 * k1);
}
