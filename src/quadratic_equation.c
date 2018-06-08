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

#include "rtv1.h"

t_vector		define_vector(double x, double y, double z)
{
	t_vector	a;

	a.x = x;
	a.y = y;
	a.z = z;
	return (a);
}

static double	specular(t_all *ev, int j, int c, double i)
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
		i += (ev->light[j].intensity *
			(pow((r_dot_v / (find_len(ev->r) *
				find_len(ev->v))), ev->figure[c].specular)));
	return (i);
}

static double	which_light(double *t_max, double i, int j, t_all *ev)
{
	(ev->light[j].type == 'a') ? i += ev->light[j].intensity : 0;
	if (ev->light[j].type == 'p')
	{
		ev->l = vector_minus_vector(ev->light[j].position, ev->p);
		*t_max = 0.99f;
	}
	if (ev->light[j].type == 'd')
	{
		ev->light[j].position = normalise(ev->light[j].position);
		ev->l = ev->light[j].position;
		*t_max = MAX;
	}
	return (i);
}

double			compute_lighting(t_all *ev, int c)
{
	double	i;
	int		j;
	double	t_max;
	double	n_l;
	double	t[2];

	i = 0.0;
	j = -1;
	while (++j < ev->num_l)
	{
		i = which_light(&t_max, i, j, ev);
		t[0] = 0.001;
		t[1] = t_max;
		closet_interesection(ev, t, ev->p, ev->l);
		if (ev->id == -1)
		{
			n_l = multy_vec(ev->n, ev->l);
			(n_l > 0) ? i += (ev->light[j].intensity * n_l
				/ (find_len(ev->n) * find_len(ev->l))) : 0;
			(ev->figure[c].specular > 0) ? i = specular(ev, j, c, i) : 0;
		}
	}
	return (i);
}
