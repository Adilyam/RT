/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 15:22:44 by atilegen          #+#    #+#             */
/*   Updated: 2018/06/17 15:22:46 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		check_if_3digit_input_help(char *str, int *i, double *res)
{
	int j;

	spaces(str, i);
	j = 0;
	while (str[(*i)] != ']')
	{
		j = ((ft_isdigit(str[(*i)])) || str[(*i)] == '-') ? j + 1 :
														error_end("3");
		(*i)++;
	}
	*res = ft_atoi(str + (*i)++ - j);
}

double		*check_if_3digit_input(char *str, int *i)
{
	static double	res[3];
	int				j;

	j = 0;
	while (str[(*i)] != ',')
	{
		j = ((ft_isdigit(str[(*i)])) || str[(*i)] == '-') ? j + 1 :
														error_end("1");
		(*i)++;
	}
	res[0] = ft_atoi(str + (*i)++ - j);
	spaces(str, i);
	j = 0;
	while (str[(*i)] != ',')
	{
		j = ((ft_isdigit(str[(*i)])) || str[(*i)] == '-') ? j + 1 :
														error_end("2");
		(*i)++;
	}
	res[1] = ft_atoi(str + (*i)++ - j);
	check_if_3digit_input_help(str, i, &res[2]);
	return (res);
}

void		check_symbol(char *str, int *i, char c)
{
	if ((str[(*i)++] != c))
		error_end("Check your symbols again ([] {}) ");
	spaces(str, i);
}

double		check_if_input_number(int *i, char *str)
{
	int j;

	j = 0;
	while (str[(*i)] > 32)
	{
		if (ft_isdigit(str[(*i)]) || str[(*i)] == '-')
		{
			j++;
			(*i)++;
		}
		else if (str[(*i)] == ',')
			return (ft_atoi((str + (*i) + 1) - (j + 1)));
	}
	return ((double)ft_atoi((str + (*i)++) - j++));
}

float		check_if_input_float(int *i, char *str)
{
	int j;

	j = 0;
	while (str[(*i)] > 32 && str[(*i)] != ',')
	{
		if (ft_isdigit(str[(*i)]) || str[(*i)] == '.')
			j++;
		(*i)++;
	}
	return (strtof((str + (*i)) - j, NULL));
}
