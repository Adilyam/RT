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
		error_end("Wrong input");
}

int check_exact_light(char *str, int i, t_all *ev)
{
	int check[7];

	spaces(str, &i);
	lights_string_validate(str, i);
	check_exact_lights_helper(str, &i, ev);
	if (str[i] == ',')
		i = check_exact_light(str, i + 1, ev);
	else if (str[i++] == '}')
	{
		spaces(str, &i);
		if (str[i] == ',') //все обнулять типа или обджект ++
		{
			i++;
			ev->index++;
			spaces(str, &i);
			if (str[i++] == '{' && ev->index <= ev->num_l)
				i = check_exact_light(str, i, ev);
		}
		else if (check_if_end(str, &i))
			error_end("seems to be no camera in your scene");
	}
	else
		error_end("Chto-to levoe posle lights");
	return (i);
}
