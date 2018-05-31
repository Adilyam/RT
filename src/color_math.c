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

#include "RTv1.h"

uint32_t	multy_col(t_color col, double j)
{
	double	temp;

	temp = col.chanels.g * j;
	if (temp > 255)
		temp = 255;
	col.chanels.g = temp;

	temp = col.chanels.r * j;
	if (temp > 255)
		temp = 255;
	col.chanels.r = temp;

	temp = col.chanels.b * j;
	if (temp > 255)
		temp = 255;
	col.chanels.b = temp;
	return (col.color);
}
