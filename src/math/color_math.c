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

#include "rt.h"

void			define_color(t_figure *figure, unsigned int b,
						unsigned int g, unsigned int r)
{
	figure->color.chanels.b = b;
	figure->color.chanels.g = g;
	figure->color.chanels.r = r;
	figure->color.chanels.a = 0;
}

t_color			multy_col(t_color col, double j)
{
	double temp;

	temp = (col.chanels.g) * j;
	if (temp > 255)
		temp = 255;
	if (temp < 0)
		temp = 0;
	col.chanels.g = temp;
	temp = (col.chanels.r) * j;
	if (temp > 255)
		temp = 255;
	if (temp < 0)
		temp = 0;
	col.chanels.r = temp;
	temp = (col.chanels.b) * j;
	if (temp > 255)
		temp = 255;
	if (temp < 0)
		temp = 0;
	col.chanels.b = temp;
	return (col);
}

t_color			sum_col(t_color col, t_color col_1)
{
	double temp;

	temp = (col.chanels.g) + col_1.chanels.g;
	if (temp > 255)
		temp = 255;
	if (temp < 0)
		temp = 0;
	col.chanels.g = temp;
	temp = (col.chanels.r) + col_1.chanels.r;
	if (temp > 255)
		temp = 255;
	if (temp < 0)
		temp = 0;
	col.chanels.r = temp;
	temp = (col.chanels.b) + col_1.chanels.b;
	if (temp > 255)
		temp = 255;
	if (temp < 0)
		temp = 0;
	col.chanels.b = temp;
	return (col);
}

t_color			color_ret(t_color local_color,
							t_color reflected_color, double r)
{
	t_color	color_2;
	t_color	color;

	color_2 = multy_col(reflected_color, r);
	color = sum_col(local_color, color_2);
	return (color);
}
