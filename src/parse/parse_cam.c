/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:50:51 by atilegen          #+#    #+#             */
/*   Updated: 2018/06/19 16:50:53 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		check_exact_camera_helper(char *str, int *i, t_all *ev)
{
	int		*res;

	if (ft_strnequ(str + (*i), "\"direction\"", 11))
	{
		(*i) += 11;
		res = parse_3_input(str, i);
		ev->o_rot = define_vector(res[0], res[1], res[2]);
	}
	else if ((ft_strnequ(str + (*i), "\"position\"", 10)))
	{
		(*i) += 10;
		res = parse_3_input(str, i);
		ev->o = define_vector(res[0], res[1], res[2]);
	}
	spaces(str, i);
}

void		camera_string_validate(char *str, int i)
{
	if (!(ft_strnequ(str + i, "\"direction\"", 11) || 
		ft_strnequ(str + i, "\"position\"", 10)))
		error_end("Wrong input");
}

int check_exact_camera(char *str, int i, t_all *ev)
{
	int check[7];

	spaces(str, &i);
	camera_string_validate(str, i);
	check_exact_camera_helper(str, &i, ev);
	if (str[i] == ',')
		i = check_exact_camera(str, i + 1, ev);
	else if (str[i++] == '}')
	{
		spaces(str, &i);
		if (str[i] == '}') //все обнулять типа или обджект ++
		{
			i++;
			spaces(str, &i);
			if (str[i] != '\0')
				error_end("Vse ok, tol'ko v konce zatupil posle cams");
		}
	}
	else
		error_end("Chto-to levoe posle cams");
	return (i);
}
