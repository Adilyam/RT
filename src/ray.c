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

#include "RTv1.h"

t_vector	reflect_ray(t_vector r, t_vector n)
{
	t_vector	k;
	t_vector	d_n;
	double		r_n;

	r_n = multy_vec(r, n);
	d_n = vector_multy_const(n, (2 * r_n));
	k = vector_minus_vector(d_n, r);
	k = normalise(k);
	return (k);
}

static void	intersect_ray_sphere(t_all *ev, int i, t_vector o, t_vector d)
{
	t_vector	oc;
	double		k1;
	double		k2;
	double		k3;
	double		discriminant;

	oc = vector_minus_vector(o, ev->sphere[i].centre);
	k1 = multy_vec(d, d);
	k2 = 2 * multy_vec(oc, d);
	k3 = (multy_vec(oc, oc)) - (pow(ev->sphere[i].radius, 2));
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

// static void	intersect_ray_plane(t_all *ev, int i, t_vector O, t_vector D)
// {
// 	t_vector	oc;
// 	double		k1;
// 	double		k2;
// 	double		k3;
// 	double		discriminant;

// 	oc = vector_minus_vector(O, ev->sphere[i].centre);
// 	k1 = multy_vec(D, D);
// 	k2 = 2 * multy_vec(oc, D);
// 	k3 = (multy_vec(oc, oc)) - (pow(ev->sphere[i].radius, 2));
// 	discriminant = (pow(k2, 2)) - (4 * k1 * k3);
// 	if (discriminant < 0)
// 	{
// 		ev->x1 = MAX;
// 		ev->x2 = MAX;
// 		return ;
// 	}
// 	ev->x1 = (-k2 + sqrt(discriminant)) / (2 * k1);
// 	ev->x2 = (-k2 - sqrt(discriminant)) / (2 * k1);
// }

double		closet_interesection(t_all *ev, double t_min, t_vector o, t_vector d)
{
	int		i;
	double	closet_t;

	closet_t = MAX;
	ev->id_sph = -1;
	i = 0;
	while (i < 4)
	{
		intersect_ray_sphere(ev, i, o, d);
		if (ev->x1 >= t_min && ev->x1 <= MAX && ev->x1 < closet_t)
		{
			ev->id_sph = i;
			closet_t = ev->x1;
		}
		if (ev->x2 >= t_min && ev->x2 <= MAX && ev->x2 < closet_t)
		{
			ev->id_sph = i;
			closet_t = ev->x2;
		}
		i++;
	}
	return (closet_t);
}
