/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:09:49 by htkachuk          #+#    #+#             */
/*   Updated: 2017/11/11 15:09:51 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count(int nm)
{
	int i;

	i = 0;
	if (nm == 0)
		i++;
	if (nm < 0)
	{
		nm = -nm;
		i++;
	}
	while (nm > 0)
	{
		nm = nm / 10;
		i++;
	}
	if (nm == -2147483648)
		i = 11;
	return (i);
}

static	char	*strin(char *s, int n, int i)
{
	while (n != 0)
	{
		s[--i] = n % 10 + 48;
		n = n / 10;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*s;

	i = count(n);
	s = (char*)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i] = '\0';
	if (n == -2147483648)
	{
		n = 214748364;
		s[0] = '-';
		s[--i] = '8';
	}
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	if (n == 0)
		s[0] = '0';
	return (s = strin(s, n, i));
}
