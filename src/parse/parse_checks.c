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

#include "rtv1.h"

void        spaces(char *str, int *i)
{
	while (str[*i] <= 32 && str[*i])
		(*i)++;
}

int     match(char a, char b)
{
	return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'));
}

int         *check_if_3digit_input(char *str, int *i)
{
	int res[3];
	int j;

	j = 0;
	while (str[(*i)] != ',')
	{
		if ((ft_isdigit(str[(*i)])) || str[(*i)] == '-')
			j++;
		else 
			error_end("Wrong number1");
		(*i)++;
	}
	res[0] = ft_atoi(str + (*i)++ - j);
	spaces(str, i);
	j = 0;
	while (str[(*i)] != ',')
	{
		if ((ft_isdigit(str[(*i)])) || str[(*i)] == '-')
			j++;
		else 
			error_end("Wrong number2");
		(*i)++;
	}
	res[1] = ft_atoi(str + (*i)++ - j);
	spaces(str, i);
	j = 0;
	while (str[(*i)] != ']')
	{
		if ((ft_isdigit(str[(*i)])) || str[(*i)] == '-')
			j++;
		else 
			error_end("Wrong number3");
		(*i)++;
	}
	res[2] = ft_atoi(str + (*i)++ - j);
	return (res);
}

void        check_symbol(char *str, int *i, char c)
{
	if ((str[(*i)++] != c))
		error_end("Net :  [] {} ");
}

int         check_if_input_number(int *i, char *str)
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
	return (ft_atoi((str + (*i)++) - j++));
}

float			check_if_input_float(int *i, char *str)
{
	int j;
	char *pend;

	j = 0;
	while (str[(*i)] > 32 && str[(*i)] != ',')
	{
		if (ft_isdigit(str[(*i)]) || str[(*i)] == '.')
			j++;
		(*i)++;
	}
	return (strtof((str + (*i)) - j, NULL));
}
