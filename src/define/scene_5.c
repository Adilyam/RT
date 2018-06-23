/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:25:09 by htkachuk          #+#    #+#             */
/*   Updated: 2018/06/07 20:25:11 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	define_spheres(t_all *ev)
{
	ev->figure[8].centre = define_vector(-2.5, -1, 30);
	define_color(&ev->figure[8], 128, 128, 128);
	define_sph_cyl(&ev->figure[8], 1.2, 50, 0);
	ev->figure[9].centre = define_vector(2.5, -1, 30);
	define_color(&ev->figure[9], 128, 128, 128);
	define_sph_cyl(&ev->figure[9], 1.2, 50, 0);
	ev->figure[10].centre = define_vector(-2, -1, 15);
	define_color(&ev->figure[10], 128, 128, 128);
	define_sph_cyl(&ev->figure[10], 1, 50, 0);
	ev->figure[11].centre = define_vector(2, -1, 15);
	define_color(&ev->figure[11], 128, 128, 128);
	define_sph_cyl(&ev->figure[11], 1, 50, 0);
	ev->figure[4].centre = define_vector(-2.5, 5, 30);
	define_color(&ev->figure[4], 128, 128, 128);
	define_sph_cyl(&ev->figure[4], 1.2, 50, 0);
	ev->figure[5].centre = define_vector(2.5, 5, 30);
	define_color(&ev->figure[5], 128, 128, 128);
	define_sph_cyl(&ev->figure[5], 1.2, 50, 0);
	ev->figure[6].centre = define_vector(-2, 5, 15);
	define_color(&ev->figure[6], 128, 128, 128);
	define_sph_cyl(&ev->figure[6], 1, 50, 0);
	ev->figure[7].centre = define_vector(2, 5, 15);
	define_color(&ev->figure[7], 128, 128, 128);
	define_sph_cyl(&ev->figure[7], 1, 50, 0);
}

static void	define_planes(t_all *ev)
{
	ev->figure[14].point = define_vector(0, -1, 0);
	ev->figure[14].centre = define_vector(0, 1, 0);
	define_color(&ev->figure[14], 0, 0, 255);
	define_sph_cyl(&ev->figure[14], 0, -1, 1);
	ev->figure[15].point = define_vector(0, 5, 0);
	ev->figure[15].centre = define_vector(0, 5, 0);
	define_color(&ev->figure[15], 0, 0, 255);
	define_sph_cyl(&ev->figure[15], 0, -1, 1);
	ev->figure[13].point = define_vector(0, 0, 40);
	ev->figure[13].centre = define_vector(0, 0, 1);
	define_color(&ev->figure[13], 255, 0, 0);
	define_sph_cyl(&ev->figure[13], 0, -1, 1);
}

static void	define_cyliders(t_all *ev)
{
	ev->figure[2].point = define_vector(0, 1, 0);
	ev->figure[2].centre = define_vector(2.5, 0, 30);
	define_color(&ev->figure[2], 128, 128, 128);
	define_sph_cyl(&ev->figure[2], 1, 50, 2);
	ev->figure[3].point = define_vector(0, 1, 0);
	ev->figure[3].centre = define_vector(-2.5, 0, 30);
	define_color(&ev->figure[3], 128, 128, 128);
	define_sph_cyl(&ev->figure[3], 1, 50, 2);
	ev->figure[1].point = define_vector(0, 1, 0);
	ev->figure[1].centre = define_vector(2, 0, 15);
	define_color(&ev->figure[1], 128, 128, 128);
	define_sph_cyl(&ev->figure[1], 0.6, 50, 2);
	ev->figure[0].point = define_vector(0, 1, 0);
	ev->figure[0].centre = define_vector(-2, 0, 15);
	define_color(&ev->figure[0], 128, 128, 128);
	define_sph_cyl(&ev->figure[0], 0.6, 50, 2);
}

// void		define_scene5(t_all *ev)
// {
// 	ev->o = define_vector(0, 1, -1);
// 	ev->o_rot = define_vector(0, 0, 0);
// 	allocate_mem(ev, 16, 3);
// 	define_spheres(ev);
// 	define_planes(ev);
// 	define_cyliders(ev);
// 	ev->figure[12].centre = define_vector(0, -0.5, 15);
// 	define_color(&ev->figure[12], 0, 0, 255);
// 	define_sph_cyl(&ev->figure[12], 0.4, 50, 0);
// 	define_type_intens(&ev->light[1], 'p', 0.4);
// 	ev->light[1].position = define_vector(30, 1, -35);
// 	define_type_intens(&ev->light[0], 'p', 0.4);
// 	define_type_intens(&ev->light[2], 'a', 0.2);
// 	ev->light[0].position = define_vector(-30, 1, -35);
// }
