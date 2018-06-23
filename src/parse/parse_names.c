/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_names.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 21:07:17 by atilegen          #+#    #+#             */
/*   Updated: 2018/06/23 21:07:21 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int     check2(char *str)
{
	int i;
	int j;
	int array[BUF_SIZE];

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			array[++j] = str[i];
		if (str[i] == ')' || str[i] == '}' || str[i] == ']')
			if (!match(array[j--], str[i]))
				return (0);
		i++;
	}
	return (!j);
}

int		check_if_end(char *str, int *i)
{
	spaces(str, i);
	check_symbol(str, i, ']');
	spaces(str, i);
	if (str[(*i)++] != ',')
		return (1);
	else
		return (0);
}

void		check_light_string(char *str, int *i, t_light *lgt)
{
	if (ft_strnequ(str + *i, "\"ambiant\"", 9))
	{
		(*i) += 9;
		lgt->type = AMBIANT;
	}
	else if (ft_strnequ(str + *i, "\"directional\"", 13))
	{
		(*i) += 13;
		lgt->type = DIRECTION;
	}
	else if (ft_strnequ(str + *i, "\"point\"", 7))
	{
		(*i) += 7;
		lgt->type = POINT;
	}
	else
		error_end("The lights part defined wrongly");
}

void	check_objects_string(char *str, int *i, t_figure *obj)
{
	if (ft_strnequ(str + *i, "\"sphere\"", 8))
	{
		(*i) += 8;
		obj->id_figure = SPHERE;
	}
	else if (ft_strnequ(str + *i, "\"plane\"", 7))
	{
		(*i) += 7;
		obj->id_figure = PLANE;
	}
	else if (ft_strnequ(str + *i, "\"cone\"", 6))
	{
		(*i) += 6;
		obj->id_figure = CONE;
	}
	else if	(ft_strnequ(str + *i, "\"cylinder\"", 10))
	{
		(*i) += 10;
		obj->id_figure = CYLINDRE;
	}
	else if	(ft_strnequ(str + *i, "\"ellipsoid\"", 11))
	{
		(*i) += 11;
		obj->id_figure = ELLIPSOID;
	}
	else if	(ft_strnequ(str + *i, "\"parabolloid\"", 13))
	{
		(*i) += 13;
		obj->id_figure = PARABOLOID;
	}
	else if	(ft_strnequ(str + *i, "\"cutted_cylinder\"", 17))
	{
		(*i) += 17;
		obj->id_figure = CYLINDRE;
	}
	else if	(ft_strnequ(str + *i, "\"cutted_cone\"", 13))
	{
		(*i) += 13;
		obj->id_figure = CONE_CUT;
	}
	else
		error_end("The objects part defined wrongly");
}

void	universal_check(char *str, int *i)
{
	spaces(str, i);
	check_symbol(str, i, ':');
	spaces(str, i);
}
