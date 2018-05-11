/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 21:55:36 by htkachuk          #+#    #+#             */
/*   Updated: 2017/11/23 21:11:02 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	long long int	res;
	long long int	neg;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == 32 || str[i] == 10 || str[i] == 9 || str[i] == 12 ||
			str[i] == 13 || str[i] == 11)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < 48 || 57 < str[i])
			return (res * neg);
		else
			res = (res * 10) + (long long int)(str[i] - '0');
		i++;
	}
	return (res * neg);
}
