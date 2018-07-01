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

#include "rt.h"

void		spaces(char *str, int *i)
{
	while (str[*i] <= 32 && str[*i])
		(*i)++;
}

int			match(char a, char b)
{
	return ((a == '(' && b == ')') || (a == '{' && b == '}')
				|| (a == '[' && b == ']'));
}

void		check_exact_camera_helper(char *str, int *i, t_all *ev)
{
	double		*res;

	if (ft_strnequ(str + (*i), "\"direction\"", 11))
	{
		(*i) += 11;
		res = parse_3_input(str, i);
		ev->cam.o_rot = define_vector(res[0], res[1], res[2]);
	}
	else if ((ft_strnequ(str + (*i), "\"position\"", 10)))
	{
		(*i) += 10;
		res = parse_3_input(str, i);
		ev->cam.o = define_vector(res[0], res[1], res[2]);
	}
	spaces(str, i);
}

void		camera_string_validate(char *str, int i)
{
	if (!(ft_strnequ(str + i, "\"direction\"", 11) ||
		ft_strnequ(str + i, "\"position\"", 10)))
		error_end("The camera part defined wrongly");
}

int			check_exact_camera(char *str, int i, t_all *ev)
{
	spaces(str, &i);
	camera_string_validate(str, i);
	check_exact_camera_helper(str, &i, ev);
	if (str[i] == ',')
		i = check_exact_camera(str, i + 1, ev);
	else if (str[i++] == '}')
	{
		spaces(str, &i);
		if (str[i] == '}')
		{
			i++;
			spaces(str, &i);
			if (str[i] != '\0')
				error_end("Vse ok, tol'ko v konce zatupil posle cams");
		}
	}
	else
		error_end("Something extra after camera definition");
	return (i);
}
