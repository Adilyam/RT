/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 14:04:38 by atilegen          #+#    #+#             */
/*   Updated: 2018/07/01 14:04:40 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
	if (ev->cam.o_rot.x != 0)
		ev->d = rotate_vec_x(&ev->d, &ev->cam.o_rot);
	if (ev->cam.o_rot.y != 0)
		ev->d = rotate_vec_y(&ev->d, &ev->cam.o_rot);
	if (ev->cam.o_rot.z != 0)
		ev->d = rotate_vec_z(&ev->d, &ev->cam.o_rot);
}
