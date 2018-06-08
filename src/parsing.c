/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 19:09:51 by htkachuk          #+#    #+#             */
/*   Updated: 2018/05/21 19:09:54 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	define_scene6(t_all *ev)
{
	ev->o = define_vector(0, 0, -1);
	ev->o_rot = define_vector(0, 0, 0);
	allocate_mem(ev, 4, 3);
	ev->figure[0].centre = define_vector(0, -1, 3);
	define_color(&ev->figure[0], 0, 0, 255);
	define_sph_cyl(&ev->figure[0], 1, 500, 0);
	ev->figure[1].centre = define_vector(2, 0, 4);
	define_color(&ev->figure[1], 255, 0, 0);
	define_sph_cyl(&ev->figure[1], 1, 500, 0);
	ev->figure[2].centre = define_vector(-2, 0, 4);
	define_color(&ev->figure[2], 0, 255, 0);
	define_sph_cyl(&ev->figure[2], 1, 10, 0);
	ev->figure[3].centre = define_vector(0, -5001, 0);
	define_color(&ev->figure[3], 0, 255, 255);
	define_sph_cyl(&ev->figure[3], 5000, 1000, 0);
	define_type_intens(&ev->light[0], 'p', 0.6);
	ev->light[0].position = define_vector(2, 1, 0);
	define_type_intens(&ev->light[1], 'd', 0.2);
	ev->light[1].position = define_vector(1, 4, 4);
	define_type_intens(&ev->light[2], 'a', 0.2);
}

void	define_scene1(t_all *ev)
{
	ev->o = define_vector(0, 0, 0);
	ev->o_rot = define_vector(0, 0, 0);
	allocate_mem(ev, 1, 1);
	ev->figure[0].centre = define_vector(0, 0, 7);
	define_color(&ev->figure[0], 0, 0, 255);
	define_sph_cyl(&ev->figure[0], 1, 10, 0);
	define_type_intens(&ev->light[0], 'p', 0.4);
	ev->light[0].position = define_vector(1.5, 0, 5);
}

void	define_scene2(t_all *ev)
{
	ev->o = define_vector(0, 0, 0);
	ev->o_rot = define_vector(0, 0, 0);
	allocate_mem(ev, 1, 1);
	ev->figure[0].point = define_vector(0, 1, 0);
	ev->figure[0].centre = define_vector(0, 0, 3);
	define_color(&ev->figure[0], 0, 255, 0);
	define_sph_cyl(&ev->figure[0], 0.5, -1, 2);
	define_type_intens(&ev->light[0], 'p', 0.3);
	ev->light[0].position = define_vector(2, 0, 0);
}

void	define_scene3(t_all *ev)
{
	ev->o = define_vector(0, 0, -10);
	ev->o_rot = define_vector(0, 0, 0);
	allocate_mem(ev, 2, 2);
	ev->figure[1].point = define_vector(0, -1, 0);
	ev->figure[1].centre = define_vector(0, 1, 0);
	define_color(&ev->figure[1], 255, 0, 0);
	define_sph_cyl(&ev->figure[1], 0, 10, 1);
	ev->figure[0].point = define_vector(0, 1, 0);
	ev->figure[0].centre = define_vector(0, 0, 30);
	define_color(&ev->figure[0], 0, 255, 255);
	define_sph_cyl(&ev->figure[0], 0.8, -1, 3);
	define_type_intens(&ev->light[0], 'p', 0.4);
	ev->light[0].position = define_vector(0, 0, -3);
	define_type_intens(&ev->light[1], 'a', 0.2);
}

void	define_scene4(t_all *ev)
{
	ev->o = define_vector(0, 0, -10);
	ev->o_rot = define_vector(0, 0, 0);
	allocate_mem(ev, 5, 2);
	ev->figure[4].point = define_vector(-0.1, -0.5, 0);
	ev->figure[4].centre = define_vector(0, 1, 0);
	define_color(&ev->figure[4], 128, 128, 128);
	define_sph_cyl(&ev->figure[4], 0, -1, 1);
	ev->figure[3].point = define_vector(0.1, 0.5, 1.5);
	ev->figure[3].centre = define_vector(0, 0, 100);
	define_color(&ev->figure[3], 255, 0, 0);
	define_sph_cyl(&ev->figure[3], 0, -1, 1);
	ev->figure[2].centre = define_vector(0, -0.35, -1.5);
	define_color(&ev->figure[2], 0, 0, 255);
	define_sph_cyl(&ev->figure[2], 0.25, 100, 0);
	ev->figure[1].point = define_vector(-1.3, 1, 0);
	ev->figure[1].centre = define_vector(0.01, 0.2, -1.3);
	define_color(&ev->figure[1], 0, 255, 255);
	define_sph_cyl(&ev->figure[1], 0.8, -1, 3);
	ev->figure[0].point = define_vector(0.5, 1, 0);
	ev->figure[0].centre = define_vector(-0.5, 0, -1.3);
	define_color(&ev->figure[0], 0, 255, 0);
	define_sph_cyl(&ev->figure[0], 0.25, -1, 2);
	define_type_intens(&ev->light[0], 'a', 0.2);
	define_type_intens(&ev->light[1], 'p', 0.6);
	ev->light[1].position = define_vector(4, 1, -4);
}
