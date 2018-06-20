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

#include "rt.h"

void saveppm(char *filename, unsigned char *img, int width, int height){

	FILE *f;
	
	f = fopen(filename, "wb");
	fprintf(f, "P6 %d %d %d\n", width, height, 255);
	fwrite(img, 3, width*height, f);
	fclose(f);
}

static void changes(t_all *ev, double *o, int m)
{
	if (m)
		*o += 0.08;
	else
		*o -= 0.08;
	thread(ev);
}

int   ft_key(int keycode, t_all *ev)
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

int   mouse_zoom(int keycode, int x, int y, t_all *ev)
{
	if (keycode == 4)
	{
		ev->o.z += 1;
		thread(ev);
	}
	if (keycode == 5)
	{
		ev->o.z -= 1;
		thread(ev);
	}
	if (keycode == 1)
	if ((x > 310 && x < 490 && y > 835 && y < 965)
		|| (x > 465 && x < 475 && y > 815 && y < 835))
		saveppm("YO.jpg", ev->screen, SIZE_X, SIZE_Y);
	if (x > 10 && x < 150 && y > 805 && y < 835)
		re_draw_effect(ev, 0);
	if (x > 10 && x < 150 && y > 845 && y < 875)
		re_draw_effect(ev, 1);
	if (x > 10 && x < 150 && y > 885 && y < 920)
		re_draw_effect(ev, 2);
	if (x > 10 && x < 150 && y > 930 && y < 960)
		re_draw_effect(ev, 3);
	return (0);
}
 

