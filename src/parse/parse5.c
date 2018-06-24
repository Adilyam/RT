/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:38:33 by atilegen          #+#    #+#             */
/*   Updated: 2018/06/19 15:38:34 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			check2(char *str)
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

int			check_if_end(char *str, int *i)
{
	spaces(str, i);
	check_symbol(str, i, ']');
	if (str[(*i)++] != ',')
		return (1);
	else
		return (0);
}

int			check_scene2(char *str, int *i)
{
	int num;

	spaces(str, i);
	if (str[(*i)++] != ':')
		error_end("Wrong input format (objects)");
	spaces(str, i);
	num = check_if_input_number(i, str);
	if (!num)
		error_end("Seems to be not a proper number (scene)");
	return (num);
}

int			check_scene(char *str, int i, t_all *ev)
{
	int check_o;
	int check_l;

	check_o = 0;
	check_l = 0;
	if (ft_strnequ(str + i, "\"object_count\"", 14))
		check_o = 1;
	else if (ft_strnequ(str + i, "\"lights_count\"", 14))
		check_l = 1;
	else
		error_end("Error (lights and obj)");
	i += 14;
	ev->num_f = check_scene2(str, &i);
	i++;
	spaces(str, &i);
	if (ft_strnequ(str + i, "\"object_count\"", 14) && !check_o)
		check_o = 1;
	else if (ft_strnequ(str + i, "\"lights_count\"", 14) && !check_l)
		check_l = 1;
	else
		error_end("lights or objects are defined wrongly");
	i += 14;
	ev->num_l = check_scene2(str, &i);
	allocate_mem(ev);
	return (i);
}
