/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 19:18:37 by htkachuk          #+#    #+#             */
/*   Updated: 2018/05/21 19:18:39 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		define_color(t_figure *figure, unsigned int b,
	unsigned int g, unsigned int r)
{
	figure->color.chanels.b = b;
	figure->color.chanels.g = g;
	figure->color.chanels.r = r;
	figure->color.chanels.a = 0;
}

uint32_t	multy_col(t_color col, double j)
{
	double	temp;

	temp = (col.chanels.g) * j;
	if (temp > 255)
		temp = 255;
	col.chanels.g = temp;
	temp = (col.chanels.r) * j;
	if (temp > 255)
		temp = 255;
	col.chanels.r = temp;
	temp = (col.chanels.b) * j;
	if (temp > 255)
		temp = 255;
	col.chanels.b = temp;
	return (col.color);
}
