/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:30:09 by htkachuk          #+#    #+#             */
/*   Updated: 2018/05/07 20:30:11 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		multy_vec(t_vector a1, t_vector a2)
{
	return (a1.x * a2.x + a1.y * a2.y + a1.z * a2.z);
}

double		find_len(t_vector a)
{
	return (sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)));
}

t_vector	normalise(t_vector a)
{
	double	len;

	len = find_len(a);
	a.x = a.x / len;
	a.y = a.y / len;
	a.z = a.z / len;
	return (a);
}

t_vector	vector_plus_vector(t_vector a, t_vector b)
{
	t_vector	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_vector	vector_minus_vector(t_vector a, t_vector b)
{
	t_vector	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}
