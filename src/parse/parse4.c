/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:27:05 by atilegen          #+#    #+#             */
/*   Updated: 2018/06/19 15:27:07 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
		error_end("Wrong object");
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
	else
		error_end("Wrong object");
}

void	universal_check(char *str, int *i)
{
	spaces(str, i);
	check_symbol(str, i, ':');
	spaces(str, i);
}