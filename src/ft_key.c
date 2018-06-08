/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:19:21 by htkachuk          #+#    #+#             */
/*   Updated: 2018/05/04 12:19:25 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	changes(t_all *ev, double *o, int m)
{
	if (m)
		*o += 0.08;
	else
		*o -= 0.08;
	draw_scene(ev);
}

int			ft_key(int keycode, t_all *ev)
{
	if (keycode == 53)
		exit(0);
	(keycode == 126) ? changes(ev, &ev->o.y, 1) : 0;
	(keycode == 125) ? changes(ev, &ev->o.y, 0) : 0;
	(keycode == 124) ? changes(ev, &ev->o.x, 1) : 0;
	(keycode == 123) ? changes(ev, &ev->o.x, 0) : 0;
	(keycode == 0) ? changes(ev, &ev->o_rot.y, 0) : 0;
	(keycode == 2) ? changes(ev, &ev->o_rot.y, 1) : 0;
	(keycode == 13) ? changes(ev, &ev->o_rot.z, 0) : 0;
	(keycode == 7) ? changes(ev, &ev->o_rot.z, 1) : 0;
	(keycode == 1) ? changes(ev, &ev->o_rot.x, 0) : 0;
	(keycode == 6) ? changes(ev, &ev->o_rot.x, 1) : 0;
	return (0);
}

int			mouse_zoom(int keycode, int x, int y, t_all *ev)
{
	x = 0;
	y = 0;
	if (keycode == 4)
	{
		ev->o.z += 0.4;
		draw_scene(ev);
	}
	if (keycode == 5)
	{
		ev->o.z -= 0.4;
		draw_scene(ev);
	}
	return (0);
}
