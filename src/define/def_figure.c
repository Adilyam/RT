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
	int j;

	j = -1;
	ev->figure = (t_figure*)malloc(sizeof(t_figure) * ev->num_f);
	ev->light = (t_light*)malloc(sizeof(t_light) * ev->num_l);
	while (++j < ev->num_f)
	{
		ev->figure[j].specular = 500;
		ev->figure[j].centre = define_vector(0, 0, 0);
		define_color(&ev->figure[j], 255 , 0, 0);
		ev->figure[j].id_figure = 0;
		ev->figure[j].max = 100;
		ev->figure[j].min = 0;
		ev->figure[j].radius = 1;
		ev->figure[j].transp = 0;
		ev->figure[j].reflect = 0;
		ev->figure[j].point = define_vector(0, 1, 0);
	}
	
	j = -1;
	while (++j < ev->num_l)
	{
		ev->light[j].intensity = 0.2;
		ev->light[j].position = define_vector(0, 0, 0);
		ev->light[j].type = AMBIANT;
	}

	ev->filter = NORMAL;
	ev->o = define_vector(0, 0, 0);
	ev->o_rot = define_vector(0, 0, 0);
}

void	normalise_obj(t_all *ev)
{
	int i;

	i = -1;
	while (++i < ev->num_f)
	{
		if (ev->figure[i].id_figure == PLANE)
			ev->figure[i].centre = normalise(ev->figure[i].centre);
		else if (ev->figure[i].id_figure == CYLINDRE ||
				ev->figure[i].id_figure == CONE || 
				ev->figure[i].id_figure == CYLINDRE_CUT ||
				ev->figure[i].id_figure == CONE_CUT)
			ev->figure[i].point = normalise(ev->figure[i].point);
	}
}

