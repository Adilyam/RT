/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_filters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 11:11:25 by htkachuk          #+#    #+#             */
/*   Updated: 2018/06/19 11:11:28 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	make_black_white(t_color *color)
{
	double	temp;

	temp = (color->chanels.r + color->chanels.g + color->chanels.b) / 3;
	color->chanels.r = temp;
	color->chanels.g = temp;
	color->chanels.b = temp;
}

void	make_cartoon(t_color *color)
{
	int		i;
	int		temp;

	i = -1;
	temp = (color->chanels.r);
	while (++i < 3)
	{
		if (temp >= 0 && temp <= 50)
			temp = 25;
		if (temp >= 50 && temp <= 100)
			temp = (50 + 100) / 2;
		if (temp >= 100 && temp <= 150)
			temp = (150 + 100) / 2;
		if (temp >= 150 && temp <= 200)
			temp = (150 + 200) / 2;
		if (temp >= 200 && temp <= 255)
			temp = (255 + 200) / 2;
		(i == 0) ? color->chanels.r = temp : 0;
		(i == 1) ? color->chanels.g = temp : 0;
		(i == 2) ? color->chanels.b = temp : 0;
		temp = ((i == 1 && i != 0) ? (color->chanels.g) : (color->chanels.b));
	}
}

void	make_sepia(t_color *color)
{
	double	tr;
	double	tg;
	double	tb;

	tr = 0.393 * color->chanels.r + 0.769 * color->chanels.g +
		0.189 * color->chanels.b;
	tg = 0.349 * color->chanels.r + 0.686 * color->chanels.g +
		0.168 * color->chanels.b;
	tb = 0.272 * color->chanels.r + 0.534 * color->chanels.g +
		0.131 * color->chanels.b;
	tr = (tr > 255) ? 255 : tr;
	tg = (tg > 255) ? 255 : tg;
	tb = (tb > 255) ? 255 : tb;
	color->chanels.r = tr;
	color->chanels.g = tg;
	color->chanels.b = tb;
}

void	define_filter(t_color *color, t_all *ev)
{
	(ev->filter == CARTOON) ? make_cartoon(color) : 0;
	(ev->filter == SEPIA) ? make_sepia(color) : 0;
	(ev->filter == BLACK_WHITE) ? make_black_white(color) : 0;
}
