/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic_equation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 18:35:04 by htkachuk          #+#    #+#             */
/*   Updated: 2018/05/04 18:35:07 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_vector		define_vector(double x, double y, double z)
{
	t_vector	a;

	a.x = x;
	a.y = y;
	a.z = z;
	return (a);
}

static double	specular(t_all *ev, int j, double i, int c)
{
	double		r_dot_v;
	t_vector	d_n;
	double		n_l;

	n_l = multy_vec(ev->n, ev->l);
	d_n = vector_multy_const(ev->n, (2 * n_l));
	ev->r = vector_minus_vector(d_n, ev->l);
	ev->r = normalise(ev->r);
	r_dot_v = multy_vec(ev->r, ev->v);
	if (r_dot_v > 0)
	{
		i += (ev->light[j].intensity *
			(pow((r_dot_v / (find_len(ev->r) *
				find_len(ev->v))), ev->sphere[c].specular)));
	}
	return (i);
}

double			compute_lighting(t_all *ev, int c)
{
	double	i;
	int		j;
	double	n_l;
	double	shadow_t;

	i = 0.0;
	j = 0;
	while (j < 3)
	{
		if (ev->light[j].type == 'a')
			i += ev->light[j].intensity;
		if (ev->light[j].type == 'p')
			ev->l = vector_minus_vector(ev->light[j].position, ev->p);
		if (ev->light[j].type == 'd')
			ev->l = ev->light[j].position;

		//shadow
		shadow_t = closet_interesection(ev, 0.001, ev->p, ev->l);
		if (ev->id_sph == -1)
		{

		//difuznost	
		n_l = multy_vec(ev->n, ev->l);
		if (n_l > 0)
			i += (ev->light[j].intensity * n_l 
				/ (find_len(ev->n) * find_len(ev->l)));
		//zerkaln
		if (ev->sphere[c].specular > 0)
			i = specular(ev, j, i, c);
	}
		j++;
	}
	return (i);
}
