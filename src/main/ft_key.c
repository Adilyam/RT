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

static void changes2(double *o, int m)
{
	if (m)
		*o += 0.08;
	else
		*o -= 0.08;
}

static void changes(double *o, int m)
{
	if (m)
		*o += 1;
	else
		*o -= 1;
}

int   ft_key(int keycode, t_all *ev)
{
	if (keycode == 53)
		exit(0);
	(keycode == 126) ? changes2(&ev->o.y, 1) : 0;
	(keycode == 125) ? changes2(&ev->o.y, 0) : 0;
	(keycode == 124) ? changes2(&ev->o.x, 1) : 0;
	(keycode == 123) ? changes2(&ev->o.x, 0) : 0;
	if (keycode == 69 && ev->k_iter < 5)
		ev->k_iter += 1;
	if (keycode == 78 && ev->k_iter > 1)
		ev->k_iter -= 1;
	(keycode == 0) ? changes(&ev->o_rot.y, 0) : 0;
	(keycode == 2) ? changes(&ev->o_rot.y, 1) : 0;
	(keycode == 13) ? changes(&ev->o_rot.z, 0) : 0;
	(keycode == 7) ? changes(&ev->o_rot.z, 1) : 0;
	(keycode == 1) ? changes(&ev->o_rot.x, 0) : 0;
	(keycode == 6) ? changes(&ev->o_rot.x, 1) : 0;
	thread(ev);
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
	if (x > 495 && x < 535 && y > 810 && y < 840)
		saveppm("YO.jpg", ev->screen, SIZE_X, SIZE_Y);
	if (x > 10 && x < 50 && y > 811 && y < 841)
		re_draw_effect(ev, 0);
	if (x > 130 && x < 170 && y > 811 && y < 841)
		re_draw_effect(ev, 1);
	if (x > 70 && x < 110 && y > 811 && y < 841)
		re_draw_effect(ev, 2);
	if (x > 190 && x < 230 && y > 811 && y < 841)
		re_draw_effect(ev, 3);
	if (x > 700 && x < 750 && y > 811 && y < 841)
		re_draw_effect(ev, 4);
	if (x > 770 && x < 820 && y > 811 && y < 841)
		re_draw_effect(ev, 5);
	return (0);
}
 

