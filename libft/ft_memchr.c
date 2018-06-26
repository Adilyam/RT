/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:13:21 by htkachuk          #+#    #+#             */
/*   Updated: 2017/10/31 18:58:33 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	const unsigned char	*s;
	size_t				i;

	s = arr;
	i = 0;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
		{
			s = &s[i];
			return ((unsigned char*)s);
		}
		i++;
	}
	return (NULL);
}
