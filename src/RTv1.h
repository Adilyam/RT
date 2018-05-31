/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:04:30 by htkachuk          #+#    #+#             */
/*   Updated: 2018/05/04 12:04:35 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define SIZE_X 800
# define SIZE_Y 800
# define MIN 1
# define MAX 2147483647

# include "mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct 		s_mlx
{
	void			*mlx;
	void			*win;
	int				size_x;
	int				size_y;
	char			*str;
	void			*img;
	int				bits;
	int				size;
	int				end;
}					t_mlx;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
	
}					t_vector;

typedef struct		s_rgb 
{
	unsigned int	b : 8;
	unsigned int	g : 8;
	unsigned int	r : 8;
	unsigned int	a : 8;
}					t_rgb;

typedef union	u_color
{
	uint32_t	color;
	t_rgb		chanels;
}				t_color;

typedef struct		s_plane
{
	t_vector		point;
	t_vector		normal;
	double			reflection;
	int 			specular;
	t_color			color;
}					t_plane;

typedef struct		s_sphere
{
	t_vector		centre;
	double			radius;
	int				specular;
	double			reflection;
	// struct s_sphere	*next;
	t_color			color;
}					t_sphere;

typedef struct		s_ray
{
	t_vector		start;
	t_vector		dir;
}					t_ray;

typedef struct 		s_light
{
	char			type;
	double			intensity;
	t_vector		position;
}					t_light;

typedef struct		s_all
{
	t_mlx		mlx;
	int			id_sph;
	double		x1;
	double		x2;
	t_vector	o;
	t_vector	c;
	t_vector	d;
	t_vector	l;
	t_vector	p;
	t_vector	n;
	t_vector	r;
	t_vector	v;
	t_sphere	*sphere;
	t_plane		*plane;
	t_light		light[3];
	double		Vw;
	double		Vh;
	int			d_d;
	uint32_t	color;
}					t_all;

void			ft_create(t_all *ev);
t_vector		vector_plus_vector(t_vector a, t_vector b);
int				ft_key(int keycode);
double			compute_lighting(t_all *ev, int c);
void			draw_scene(t_all *ev);
void			define(t_all *ev);
t_vector 		normalise(t_vector a);
double			multy_vec(t_vector a1, t_vector a2);
double			find_len(t_vector a);
t_vector		vector_minus_vector(t_vector a, t_vector b);
t_vector		define_vector(double x, double y, double z);
void			define_light(t_all *ev);
t_vector		vector_div_const(t_vector A, double b);
t_vector		vector_multy_const(t_vector A, double b);
t_vector		vector_plus_const(t_vector A, double b);
t_vector		vector_minus_const(t_vector A, double b);
double			closet_interesection(t_all *ev, double t_min, t_vector O, t_vector D);
uint32_t		multy_col(t_color col, double j);
void			open_read(t_all *ev, char *av);

#endif
