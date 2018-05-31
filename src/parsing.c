/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 19:09:51 by htkachuk          #+#    #+#             */
/*   Updated: 2018/05/21 19:09:54 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

// static void	check_valid(char *str, char *line)
// {
// 	if (!(ft_strcmp(str, line)))
// 		exit (0);
// }

// static void check_line(char *line, t_all *ev, unsigned int i)
// {
// 	char	**str;
// 	int		j;

// 	j = 0;


// 	ev->d_d = 1;


// 	i == 1 ? check_valid("sphere", line) : 0;
// 	if (i == 2)
// 	{
// 		str = ft_strsplit(line, ' ');
// 		// check_valid("		sphere", str[0]);
// 		j = ft_atoi(str[2]);
// 		ev->sphere = (t_sphere*)malloc(sizeof(t_sphere) * j);
// 	}
// }

// void	open_read(t_all *ev, char *av)
// {
// 	int				fd;
// 	char			*line;
// 	unsigned int	i;

// 	fd = open(av, O_RDONLY);
// 	line = NULL;
// 	i = 1;
// 	while (get_next_line(fd, &line))
// 	{
// 		check_line(line, ev, i);
// 		free(line);
// 		i++;
// 	}
// }

void	define(t_all *ev)
{
	ev->o.x = 0;
	ev->o.y = 0;
	ev->o.z = -10;

	ev->sphere[0].centre = define_vector(0, -1, 3);
	ev->sphere[0].radius = 1;
	ev->sphere[0].color.chanels.b = 0;
	ev->sphere[0].color.chanels.g = 0;
	ev->sphere[0].color.chanels.r = 255; // red
	ev->sphere[0].color.chanels.a = 0;
	ev->sphere[0].specular = 500;
	ev->sphere[0].reflection = 0.2;
	 
	ev->sphere[1].centre = define_vector(2, 0, 4);
	ev->sphere[1].radius = 1;
	ev->sphere[1].color.chanels.b = 255;
	ev->sphere[1].color.chanels.g = 0;
	ev->sphere[1].color.chanels.r = 0; //blue
	ev->sphere[1].color.chanels.a = 0;
	ev->sphere[1].specular = 500;
	ev->sphere[1].reflection = 0.3;

	ev->sphere[2].centre = define_vector(-2, 0, 4);
	ev->sphere[2].radius = 1;
	ev->sphere[2].color.chanels.b = 0;
	ev->sphere[2].color.chanels.g = 255;
	ev->sphere[2].color.chanels.r = 0; //green
	ev->sphere[2].color.chanels.a = 0;
	ev->sphere[2].specular = 10;
	ev->sphere[2].reflection = 0.4;

	ev->sphere[3].centre = define_vector(0, -5001, 0);
	ev->sphere[3].radius = 5000;
	ev->sphere[3].color.chanels.b = 0;
	ev->sphere[3].color.chanels.g = 255;
	ev->sphere[3].color.chanels.r = 255; //yellow
	ev->sphere[3].color.chanels.a = 0;
	ev->sphere[3].specular = 1000;
	ev->sphere[3].reflection = 0.5;



	ev->Vw = 1;
	ev->Vh = 1;
	ev->d_d = 1;
}

void	define_light(t_all *ev)
{
	ev->light[0].type = 'a';
	ev->light[0].intensity = 0.2;
	ft_bzero(&ev->light[0].position, sizeof(t_vector));

	ev->light[1].type = 'p';
	ev->light[1].intensity = 0.6;
	ev->light[1].position = define_vector(2, 1, 0);

	ev->light[2].type = 'd';
	ev->light[2].intensity = 0.2;
	ev->light[2].position = define_vector(1, 4, 4);
}