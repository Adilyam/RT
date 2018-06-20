/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_cut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:01:40 by htkachuk          #+#    #+#             */
/*   Updated: 2018/06/19 14:01:41 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	which_min(double *x, double *y)
{
	double	temp;

	if (*x > *y)
	{
		temp = *x;
		*x = *y;
		*y = temp;
	}
}

void	cut_cylinder(t_all *ev, int i, t_vector d, t_vector oc)
{
	double	k1;

	if (ev->figure[i].id_figure != CONE)
		ev->figure[i].min = 0;
	if (ev->figure[i].min < 0 || ev->figure[i].max < 0
		|| ev->figure[i].max <= ev->figure[i].min)
		return ;
	which_min(&ev->x1, &ev->x2);
	if (ev->x1 > 0)
	{
		k1 = multy_vec(d, ev->figure[i].point) * ev->x1 + 
		multy_vec(oc, ev->figure[i].point);
		if (k1 > ev->figure[i].min && k1 < ev->figure[i].max)
			return ;
	}
	if (ev->x2 > 0)
	{
		k1 = multy_vec(d, ev->figure[i].point) * ev->x2 + 
		multy_vec(oc, ev->figure[i].point);
		ev->x1 = ev->x2;
		if (k1 > ev->figure[i].min && k1 < ev->figure[i].max)
			return ;
	}
	ev->x1 = MAX;
	ev->x2 = MAX;
}

void	intersect_ray_elips(t_all *ev, int i, t_vector o, t_vector d)
{
	t_vector	oc;
	double		k[3];
	double		a[2];
	double		discriminant;

	ev->figure[i].point = normalise(ev->figure[i].point);
	oc = vector_minus_vector(o, ev->figure[i].centre);
	a[0] = 2 * ev->figure[i].k * multy_vec(d, ev->figure[i].point);
	a[1] = pow(ev->figure[i].radius, 2) + (2 * ev->figure[i].k) * multy_vec(oc, ev->figure[i].point) - ev->figure[i].k;
	k[0] = multy_vec(vector_multy_const(d, 4 * pow(ev->figure[i].radius, 2)), d) - pow(a[0], 2);
	k[1] = multy_vec(vector_multy_const(d, 4 * pow(ev->figure[i].radius, 2)), oc) - a[0] * a[1];
	k[1] *= 2;
	k[2] = multy_vec(vector_multy_const(oc, 4 * pow(ev->figure[i].radius, 2)), oc) - pow(a[1], 2);
	discriminant = (pow(k[1], 2)) - (4 * k[0] * k[2]);
	if (discriminant < 0)
	{
		ev->x1 = MAX;
		ev->x2 = MAX;
		return ;
	}
	ev->x1 = (-k[1] + sqrt(discriminant)) / (2 * k[0]);
	ev->x2 = (-k[1] - sqrt(discriminant)) / (2 * k[0]);
}

void	intersect_ray_par(t_all *ev, int i, t_vector o, t_vector d)
{
	t_vector	oc;
	double		k1;
	double		k2;
	double		k3;
	double		discriminant;

	ev->figure[i].point = normalise(ev->figure[i].point);
	oc = vector_minus_vector(o, ev->figure[i].centre);
	k1 = multy_vec(d, d);
	k1 -= pow((multy_vec(d, ev->figure[i].point)), 2);
	k2 = multy_vec(oc, d);
	k2 -= (multy_vec(d, ev->figure[i].point) *
		(multy_vec(oc, ev->figure[i].point) + 2 * ev->figure[i].k));
	k2 = 2 * k2;
	k3 = (multy_vec(oc, oc));
	k3 -= multy_vec(oc, ev->figure[i].point) * (multy_vec(oc, ev->figure[i].point) + 4 * ev->figure[i].k);
	discriminant = (pow(k2, 2)) - (4 * k1 * k3);
	if (discriminant < 0)
	{
		ev->x1 = MAX;
		ev->x2 = MAX;
		return ;
	}
	ev->x1 = (-k2 + sqrt(discriminant)) / (2 * k1);
	ev->x2 = (-k2 - sqrt(discriminant)) / (2 * k1);
	cut_cylinder(ev, i, d, oc);
}
