/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:33:32 by htkachuk          #+#    #+#             */
/*   Updated: 2018/05/04 12:33:35 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_color	use_light(t_all *ev, double closet_t, int i, t_vector o, t_vector d)
{
	double	j;
	t_color	color;

	ev->v = define_vector(0 - (d.x), 0 - (d.y), (0 - d.z));
	ev->v = normalise(ev->v);
	ev->p = vector_plus_vector(o, (vector_multy_const(d, closet_t)));
	// ev->p = vector_multy_const(ev->p, 0.00001);
	figure_type_other(i, ev, closet_t, o, d);
	ev->n = normalise(ev->n);
	j = compute_lighting(ev, i);
	color = multy_col(ev->figure[i].color, j);
	return (color);
}

t_vector reflect_ray(t_vector r, t_vector n)
{
	t_vector	k;
	double		n_dot_r;

	n_dot_r = multy_vec(r, n);
	k = vector_multy_const(n, (2.0 * n_dot_r));
	k =  vector_minus_vector(k, r);
	k = normalise(k);
	return (k);
}

static t_color	trace_ray(t_all *ev, t_vector o, t_vector d, int i, int j)
{
	double		closet_t;
	double		t[2];
	t_color		local_color;
	t_color		reflected_color;
	t_color		transparency_color;
	double		r;
	t_vector	rr;

	if (i)
		t[0] = 1;
	else
		t[0] = 0.001f;
	transparency_color.chanels.r = 0;
	transparency_color.chanels.b = 0;
	transparency_color.chanels.g = 0;
	reflected_color.chanels.r = 0;
	reflected_color.chanels.b = 0;
	reflected_color.chanels.g = 0;
	t[1] = MAX;
	closet_t = closet_interesection(ev, t, o, d);
	if (ev->id == -1)
	{
		local_color.color = 0x000000;
		return (local_color);
	}
	local_color = use_light(ev, closet_t, ev->id, o, d);
	r = ev->figure[ev->id].reflect;
	// if (depth == 0)
	// 	return (local_color);
	// printf("%d", ev->depth);
	rr =  reflect_ray(vector_multy_const(d, -1), ev->n);
	if (--ev->depth >= 0 && j == 0)
	{
		transparency_color.chanels.r = 0;
		transparency_color.chanels.b = 0;
		transparency_color.chanels.g = 0;
		reflected_color = trace_ray(ev, ev->p, rr, 0, 0);
	}
	else if (--ev->depth_trans >= 0 && j == 1)
	{
		reflected_color.chanels.r = 0;
		reflected_color.chanels.b = 0;
		reflected_color.chanels.g = 0;
		transparency_color = trace_ray(ev, ev->p, ev->d, 0, 1);
	}
 
	return (color_ret(local_color, reflected_color, transparency_color, 0.9, 0));
}

void		ft_put_pxl(t_all *ev, int x, int y, t_color *c)
{
	int		i;
	int		j;

	j = -1;
	while (++j < ev->k_iter)
	{
		i = (x * 4) + (y * ev->mlx.size);
		i += (4 * j);
		ev->mlx.str[i] =  c->chanels.b;
		ev->mlx.str[++i] = c->chanels.g;
		ev->mlx.str[++i] = c->chanels.r;
		ev->mlx.str[++i] = 1;

		i = (x + y * SIZE_Y) * 3;
		i += (3 * j);
		ev->screen[i] = c->chanels.r;
		ev->screen[++i] = c->chanels.g;
		ev->screen[++i] = c->chanels.b;	
	}
}

void		set_vector_dir(t_all *ev)
{
	ev->d.x = ((ev->x - SIZE_X / 2) * (ev->vw / SIZE_X / 2));
	ev->d.y = (-(ev->y - SIZE_Y / 2) * (ev->vh / SIZE_Y / 2));
	ev->d.z = ev->d_d;
	ev->d = normalise(ev->d);
}

void		define_filter(t_color *color, t_all *ev)
{
	(ev->filter == CARTOON) ? make_cartoon(color) : 0;
	(ev->filter == SEPIA) ? make_sepia(color) : 0;
	(ev->filter == BLACK_WHITE) ? make_black_white(color) : 0;
}

void		*draw_scene(void *data)
{
	t_color	color;
	// t_color	color2;
	t_all	*ev;
	double	tmp;

	ev = data;
	tmp = ev->y;
	ev->x = 0;
	while (ev->x < SIZE_X)
	{
		ev->y = tmp;
		while (ev->y < ev->limit)
		{
			set_vector_dir(ev);
			rot_figure(ev);
			ev->depth = 0;
			ev->depth_trans = 2;
			color = trace_ray(ev, ev->o, ev->d, 1, 1);
			// ev->depth = 2;
			// color2 = trace_ray(ev, ev->o, ev->d, 1, 1);
			// color = sum_col(color, color2);
			define_filter(&color, ev);
			ft_put_pxl(ev, ev->x, ev->y, &color);
			ev->y++;
		}
		ev->x += ev->k_iter;
	}
	pthread_exit(0);
}

void	thread(t_all *e)
{
	pthread_t	tid[20];
	t_all		env_arr[20];
	int i;
	i = 0;

	e->depth = 0;
	while (i < 20)
	{
		env_arr[i] = *e;
		env_arr[i].y = 40 * i;
		env_arr[i].limit = 40 * (i + 1);
		i++;
	}
	i = 0;
	while (++i <= 20)
		pthread_create(&tid[i - 1], NULL, draw_scene, &env_arr[i - 1]);
	while (i--)
		pthread_join(tid[i], NULL);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
}
