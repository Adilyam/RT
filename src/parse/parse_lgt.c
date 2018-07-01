/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lgt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:50:35 by atilegen          #+#    #+#             */
/*   Updated: 2018/06/19 16:50:36 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		object_string_validate(char *str, int i)
{
	if (!(ft_strnequ(str + i, "\"position\"", 10) ||
			ft_strnequ(str + i, "\"size\"", 6) ||
			ft_strnequ(str + i, "\"name\"", 6) ||
			ft_strnequ(str + i, "\"color\"", 7) ||
			ft_strnequ(str + i, "\"specularity\"", 13) ||
			ft_strnequ(str + i, "\"direction\"", 11) ||
			ft_strnequ(str + i, "\"max\"", 5) ||
			ft_strnequ(str + i, "\"min\"", 5) ||
			ft_strnequ(str + i, "\"k\"", 3)))
		error_end("The objects part defined wrongly");
}

double		*parse_3_input(char *str, int *i)
{
	double		*res;

	universal_check(str, i);
	check_symbol(str, i, '[');
	spaces(str, i);
	res = check_if_3digit_input(str, i);
	return (res);
}

void		check_exact_lights_helper(char *str, int *i, t_all *ev)
{
	double		*res;

	if ((ft_strnequ(str + (*i), "\"position\"", 10)))
	{
		(*i) += 10;
		res = parse_3_input(str, i);
		ev->light[ev->index].position.x = res[0];
		ev->light[ev->index].position.y = res[1];
		ev->light[ev->index].position.z = res[2];
	}
	else if (ft_strnequ(str + (*i), "\"intensity\"", 11))
	{
		(*i) += 11;
		universal_check(str, i);
		ev->light[ev->index].intensity = check_if_input_float(i, str);
	}
	else if ((ft_strnequ(str + (*i), "\"type\"", 6)))
	{
		(*i) += 6;
		universal_check(str, i);
		check_light_string(str, i, &ev->light[ev->index]);
	}
	spaces(str, i);
}

void		lights_string_validate(char *str, int i)
{
	if (!(ft_strnequ(str + i, "\"intensity\"", 11) ||
		ft_strnequ(str + i, "\"position\"", 10) ||
		ft_strnequ(str + i, "\"type\"", 6)))
		error_end("The lights part defined wrongly");
}

int			check_exact_light(char *str, int i, t_all *ev)
{
	spaces(str, &i);
	lights_string_validate(str, i);
	check_exact_lights_helper(str, &i, ev);
	if (str[i] == ',')
		i = check_exact_light(str, i + 1, ev);
	else if (str[i++] == '}')
	{
		spaces(str, &i);
		if (str[i] == ',')
		{
			i++;
			ev->index++;
			spaces(str, &i);
			if (str[i++] == '{' && ev->index < ev->num_l)
				i = check_exact_light(str, i, ev);
		}
		else if (check_if_end(str, &i))
			error_end("Seems to be no camera in your scene");
	}
	else
		error_end("Something extra after lights definition");
	return (i);
}
