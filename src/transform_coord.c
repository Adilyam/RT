/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:33:32 by htkachuk          #+#    #+#             */
/*   Updated: 2018/05/04 12:33:35 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int k = 1;

void	define(t_all *ev)
{
	ev->O.x = 0;
	ev->O.y = 0;
	ev->O.z = 0;

	ev->sphere[0].centre = define_vector(0, -1, 3);
	ev->sphere[0].radius = 1;
	ev->sphere[0].color.chanels.b = 0;
	ev->sphere[0].color.chanels.g = 0;
	ev->sphere[0].color.chanels.r = 255;
	ev->sphere[0].color.chanels.a = 120;
	
	ev->sphere[1].centre = define_vector(2, 0, 4);
	ev->sphere[1].radius = 1;
	ev->sphere[1].color.chanels.b = 255;
	ev->sphere[1].color.chanels.g = 0;
	ev->sphere[1].color.chanels.r = 0;
	ev->sphere[1].color.chanels.a = 120;

	ev->sphere[2].centre = define_vector(-2, 0, 4);
	ev->sphere[2].radius = 1;
	ev->sphere[2].color.chanels.b = 0;
	ev->sphere[2].color.chanels.g = 255;
	ev->sphere[2].color.chanels.r = 0;
	ev->sphere[2].color.chanels.a = 120;

	ev->sphere[3].centre = define_vector(0, -5001, 0);
	ev->sphere[3].radius = 5000;
	ev->sphere[3].color.chanels.b = 0;
	ev->sphere[3].color.chanels.g = 255;
	ev->sphere[3].color.chanels.r = 255;
	ev->sphere[3].color.chanels.a = 120;

	ev->Vw = 1;
	ev->Vh = 1;
	ev->d = 1;
}

static void	canvas_to_viewpoint(double x, double y, t_all *ev)
{
	ev->D.x = ((x - SIZE_X / 2) * (ev->Vw / (SIZE_X))); /////////////// SIZEX / 2
	ev->D.y = (-(y - SIZE_Y / 2) * (ev->Vh / (SIZE_Y))); //////////////////// SIZEY / 2
	ev->D.z = ev->d;
	ev->D = normalise(ev->D);
}

static void	intersect_ray_sphere(t_all *ev, int i)
{
	t_vector	oc;
	double		k1;
	double		k2;
	double		k3;
	double		discriminant;

	oc = vector_minus_vector(ev->O, ev->sphere[i].centre);
	k1 = multy_vec(ev->D, ev->D);
	k2 = 2 * multy_vec(oc, ev->D);
	k3 = multy_vec(oc, oc) - pow(ev->sphere[i].radius, 2);
	discriminant = k2 * k2 - 4 * k1 * k3;
	if (discriminant < 0)
	{
		ev->x1 = MAX;
		ev->x2 = MAX;
	}
	ev->x1 = (-k2 + sqrt(discriminant) / (2 * k1));
	ev->x2 = (-k2 - sqrt(discriminant) / (2 * k1));
}

static void	use_light(t_all *ev, double closet_t, int i)
{
	double	j;
	double	temp;
	t_color	col;

	ev->P = vector_plus_vector(ev->O, (vector_multy_const(ev->D, closet_t)));
	// ev->P = normalise(ev->P);
	ev->N = vector_minus_vector(ev->P, ev->sphere[i].centre);
	ev->N = normalise(ev->N);
	j = compute_lighting(ev);

	col.color = ev->sphere[i].color.color;
	temp = ev->sphere[i].color.chanels.r * j;
	if (temp > 255)
	{
		printf("temp %f\n", temp);
		temp = 255;
	}
	col.chanels.r = temp;

	temp = ev->sphere[i].color.chanels.g * j;
	if (temp > 255)
	{
				printf("temp %f\n", temp);
		temp = 255;
	}
	col.chanels.g = temp;

	temp = ev->sphere[i].color.chanels.b * j;
	if (temp > 255)
	{
				printf("temp %f\n", temp);
		temp = 255;
	}
	col.chanels.b = temp;

	ev->color = col.color;
}

static void	trace_ray_sphere(t_all *ev)
{
	double	closet_t;
	int		metka;
	int		i;

	closet_t = MAX;
	metka = -1;
	i = 0;
	while (i < 4)
	{
		intersect_ray_sphere(ev, i);
		if (ev->x1 > MIN && ev->x1 < MAX && ev->x1 < closet_t)
		{
			metka = i;
			closet_t = ev->x1;
		}
		if (ev->x2 > MIN && ev->x2 < MAX && ev->x2 < closet_t)
		{
			metka = i;
			closet_t = ev->x2;
		}
		i++;
	}
	if (metka != -1)
		use_light(ev, closet_t, metka);
	else
		ev->color = 0xFFFFFF;
	// t_vector	X;

	// X = vector_minus_vector(ev->O, ev->sphere.centre);
	// ev->a = multy_vec(ev->D, ev->D);
	// ev->b = 2 * multy_vec(ev->D, X);
	// ev->c = multy_vec(X, X) - pow(ev->sphere.radius, 2);
	// if (solve_quadr_equat(ev->a, ev->b, ev->c, ev))
	// 	ev->color = 0xff0000;
	// else
	// 	ev->color = 0x000000;
}

void	draw_scene(t_all *ev)
{
	int	x;
	int	y;

	y = 0;
	while (y < SIZE_Y)
	{
		x = 0;
		while (x < SIZE_X)
		{
			canvas_to_viewpoint((double)x, (double)y, ev);
			trace_ray_sphere(ev);
			*(unsigned int *)(ev->mlx.str + (((x)
			+ (y) * SIZE_Y) * 4)) = ev->color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(ev->mlx.mlx, ev->mlx.win, ev->mlx.img, 0, 0);
}
