/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:50:23 by atilegen          #+#    #+#             */
/*   Updated: 2018/06/19 16:50:24 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		*parse_3_input(char *str, int *i)
{
	double		*res;

	universal_check(str, i);
	check_symbol(str, i, '[');
	spaces(str, i);
	res = check_if_3digit_input(str, i);
	return (res);
}

void		object_string_validate(char *str, int i)
{
	if (!(ft_strnequ(str + i, "\"position\"", 10) || 
			ft_strnequ(str + i, "\"size\"", 6) || 
			ft_strnequ(str + i, "\"name\"", 6) || 
			ft_strnequ(str + i, "\"color\"", 7) || 
			ft_strnequ(str + i, "\"specularity\"", 13) || 
			ft_strnequ(str + i, "\"tan\"", 5) || 
			ft_strnequ(str + i, "\"direction\"", 11) ||
			ft_strnequ(str + i, "\"transparency\"", 14) ||
			ft_strnequ(str + i, "\"reflection\"", 12)))
		error_end("The lights part defined wrongly");
}


void		check_exact_object_helper2(char *str, int *i, t_all *ev)
{
	double		*res;

	if ((ft_strnequ(str + (*i), "\"position\"", 10)))
	{
		(*i) += 10;
		res = parse_3_input(str, i);
		ev->figure[ev->index].centre = define_vector(res[0], res[1], res[2]);
	}
	else if ((ft_strnequ(str + (*i), "\"direction\"", 11)))
	{
		(*i) += 11;
		res = parse_3_input(str, i);
		ev->figure[ev->index].point = define_vector(res[0], res[1], res[2]);
	}
	else if ((ft_strnequ(str + (*i), "\"name\"", 6)))
	{
		(*i) += 6;
		universal_check(str, i);
		check_objects_string(str, i, &ev->figure[ev->index]);
	}
	else if ((ft_strnequ(str + (*i), "\"color\"", 7)))
	{
		(*i) += 7;
		res = parse_3_input(str, i);
		define_color(&ev->figure[ev->index], res[2], res[1], res[0]);
	}
}

void		check_exact_object_helper(char *str, int *i, t_all *ev)
{
	if ((ft_strnequ(str + (*i), "\"size\"", 6)))
	{
		(*i) += 6;
		universal_check(str, i);
		ev->figure[ev->index].radius = check_if_input_float(i, str);
	}
	else if (ft_strnequ(str + (*i), "\"specularity\"", 13))
	{
		(*i) += 13;
		universal_check(str, i);
		ev->figure[ev->index].specular = check_if_input_float(i, str);
	}
	else if (ft_strnequ(str + (*i), "\"reflection\"", 12))
	{
		(*i) += 12;
		universal_check(str, i);
		ev->figure[ev->index].reflect = check_if_input_float(i, str);
	}
	else if (ft_strnequ(str + (*i), "\"transparency\"", 14))
	{
		(*i) += 14;
		universal_check(str, i);
		ev->figure[ev->index].reflect = check_if_input_float(i, str);
	}
	else
		check_exact_object_helper2(str, i, ev);
}

int check_exact_object(char *str, int i, t_all *ev)
{
	spaces(str, &i);
	object_string_validate(str, i);
	check_exact_object_helper(str, &i, ev);
	spaces(str, &i);
	if (str[i] == ',')
		i = check_exact_object(str, i + 1, ev);
	else if (str[i++] == '}')
	{
		spaces(str, &i);
		if (str[i] == ',') //все обнулять типа или обджект ++
		{
			i++;
			spaces(str, &i);
			ev->index++;
			if (str[i++] == '{' && ev->index < ev->num_f)
				i = check_exact_object(str, i, ev);
		}
		else if (check_if_end(str, &i))
			error_end("Seems to be no lights in your scene");
	}
	else
		error_end("Something extra after objects definition");
	return (i);
}