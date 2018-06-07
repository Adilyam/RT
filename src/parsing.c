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

void	parsing(char *str, t_all *ev)
{
	ev->vw = 1;
	ev->vh = 1;
	ev->d_d = 1;
	ev->func1 = NULL;
	if (!(ft_strcmp(str, "scene1")))
		ev->func1 = &define_scene1;
	if (!(ft_strcmp(str, "scene2")))
		ev->func1 = &define_scene2;
	if (!(ft_strcmp(str, "scene3")))
		ev->func1 = &define_scene3;
	if (!(ft_strcmp(str, "scene4")))
		ev->func1 = &define_scene4;
	if (!(ft_strcmp(str, "scene5")))
		ev->func1 = &define_scene5;
	if (!ev->func1)
	{
		ft_putstr_fd("usage:\t./RTv1 scene1\n", 2);
		ft_putstr_fd("\t./RTv1 scene2\n", 2);
		ft_putstr_fd("\t./RTv1 scene3\n\t", 2);
		ft_putstr_fd("./RTv1 scene4\n\t./RTv1 scene5\n", 2);
		exit(1);
	}
}

void	define_scene1(t_all *ev)
{
	ev->o = define_vector(0, 0, 0);
	ev->o_rot = define_vector(0, 0, 0);
	allocate_mem(ev, 1, 1);
	ev->figure[0].centre = define_vector(0, 0, 7);
	define_color(&ev->figure[0], 0, 0, 255);
	define_sph_cyl(&ev->figure[0], 1, 1, 0);
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
	ev->o = define_vector(0, 0, 0);
	ev->o_rot = define_vector(0, 0, 0);
	allocate_mem(ev, 2, 1);
	ev->figure[1].point = define_vector(0, -1, 0);
	ev->figure[1].centre = define_vector(0, 1, 0);
	define_color(&ev->figure[1], 255, 0, 0);
	define_sph_cyl(&ev->figure[1], 0, 10, 1);
	ev->figure[0].point = define_vector(0, 1, 0);
	ev->figure[0].centre = define_vector(0, 0, 13);
	define_color(&ev->figure[0], 0, 255, 255);
	define_sph_cyl(&ev->figure[0], 0.8, -1, 3);
	define_type_intens(&ev->light[0], 'p', 0.5);
	ev->light[0].position = define_vector(0, 0, -4);
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
