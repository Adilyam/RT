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

t_vector	define_vector(double x, double y, double z)
{
	t_vector	A;

	A.x = x;
	A.y = y;
	A.z = z;
	return (A);
}

void	define_light(t_all *ev)
{
	ev->light[0].type = 'a';
	ev->light[0].intensity = 0.2;
	ft_bzero(&ev->light[0].position, sizeof(t_vector));

	ev->light[1].type = 'p';
	ev->light[1].intensity = 0.6;
	ev->light[1].position = define_vector(2, 1, 0);

	ev->light[2].type = 'd';
	ev->light[2].intensity = 0.2;
	ev->light[2].position = define_vector(1, 4, 4);
}

double	compute_lighting(t_all *ev)
{
	double	i;
	int		j;
	double	n_l;

	i = 0.0;
	j = 0;
	while(j < 3)
	{
		if (ev->light[j].type == 'a')
			i += ev->light[j].intensity;
		else
			if (ev->light[j].type == 'p')
				ev->L = vector_minus_vector(ev->light[j].position, ev->P);
			else
				ev->L = ev->light[j].position;
		if ((n_l = multy_vec(ev->N, ev->L)) > 0)
			i += ev->light[j].intensity * n_l / (find_len(ev->N) * find_len(ev->L));
		j++;
	}
	return (i);
}

// int	solve_quadr_equat(double a, double b, double c, t_all *ev)
// {
// 	double	d;

// 	d = pow(b, 2) - 4 * a * c;
// 	// printf("d = %f\n", d);
// 	if (d >= 0)
// 	{
// 		ev->x1 = (-b + sqrt(d)) / (2 * a);
// 		ev->x2 =  (-b - sqrt(d)) / (2 * a);
// 		return (1);
// 	}
// 	return (0);
// }
