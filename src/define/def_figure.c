/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_figure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 20:30:39 by htkachuk          #+#    #+#             */
/*   Updated: 2018/06/04 20:30:41 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	allocate_mem(t_all *ev)
{
	ev->figure = (t_figure*)malloc(sizeof(t_figure) * ev->num_f);
	ev->light = (t_light*)malloc(sizeof(t_light) * ev->num_l);
}

void	define_sph_cyl(t_figure *figure, double radius, int specular, int id)
{
	figure->id_figure = id;
	if (id == PLANE)
		figure->centre = normalise(figure->centre);
	figure->radius = radius;
	figure->specular = specular;
	if (id == CYLINDRE || id == CONE)
		figure->point = normalise(figure->point);
}

void	define_type_intens(t_light *l, int c, double i)
{
	l->type = c;
	l->intensity = i;
	ft_bzero(&l->position, sizeof(t_vector));
}
