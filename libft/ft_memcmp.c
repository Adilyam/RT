/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:01:08 by htkachuk          #+#    #+#             */
/*   Updated: 2017/10/31 19:19:05 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t				i;
	const unsigned char	*f;
	const unsigned char	*s;

	s = arr2;
	f = arr1;
	i = 0;
	while (i < n)
	{
		if (f[i] != s[i])
			return ((int)(f[i] - s[i]));
		i++;
	}
	return (0);
}
