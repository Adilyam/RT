/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ua_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:43:34 by htkachuk          #+#    #+#             */
/*   Updated: 2018/06/15 17:43:36 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			saveppm(char *filename, unsigned char *img,
						int width, int height)
{
	FILE *f;

	f = fopen(filename, "wb");
	fprintf(f, "P6 %d %d %d\n", width, height, 255);
	fwrite(img, 3, width * height, f);
	fclose(f);
}

static void		yellow(t_all *ev, int xy[4])
{
	int		x;
	int		y;

	y = xy[2] - 1;
	while (++y < xy[3])
	{
		x = xy[0] - 1;
		while (++x < xy[1])
			mlx_pixel_put(ev->mlx.mlx, ev->mlx.win, x, y, 0xadadad);
	}
}

void			re_draw_effect(t_all *ev, int i)
{
	if (i == 0)
		ev->filter = CARTOON;
	if (i == 1)
		ev->filter = SEPIA;
	if (i == 2)
		ev->filter = BLACK_WHITE;
	if (i == 3)
		ev->filter = NORMAL;
	if (i == 4)
	{
		ev->transp = (ev->transp == 0) ? 1 : 0;
		ev->reflect = 0;
	}
	if (i == 5)
	{
		ev->reflect = (ev->reflect == 0) ? 1 : 0;
		ev->transp = 0;
	}
	thread(ev);
}

int				*set_array(int a, int b, int c, int d)
{
	static int		arr[4];

	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	arr[3] = d;
	return (arr);
}

void			change_effect(t_all *ev)
{
	yellow(ev, set_array(10, 50, 811, 841));
	yellow(ev, set_array(130, 170, 811, 841));
	yellow(ev, set_array(70, 110, 811, 841));
	yellow(ev, set_array(190, 230, 811, 841));
	yellow(ev, set_array(700, 750, 811, 841));
	yellow(ev, set_array(770, 820, 811, 841));
	mlx_string_put(ev->mlx.mlx, ev->mlx.win, 28, 815, 0x000000, "c");
	mlx_string_put(ev->mlx.mlx, ev->mlx.win, 148, 815, 0x000000, "s");
	mlx_string_put(ev->mlx.mlx, ev->mlx.win, 88, 815, 0x000000,
											"b");
	mlx_string_put(ev->mlx.mlx, ev->mlx.win, 208, 815, 0x000000, "n");
	mlx_string_put(ev->mlx.mlx, ev->mlx.win, 722, 815, 0x000000,
											"t");
	mlx_string_put(ev->mlx.mlx, ev->mlx.win, 792, 815, 0x000000, "r");
}
