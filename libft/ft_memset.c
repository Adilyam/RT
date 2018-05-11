/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 20:46:44 by htkachuk          #+#    #+#             */
/*   Updated: 2017/10/31 18:38:00 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	*k;

	k = dest;
	i = 0;
	while (i < n)
	{
		k[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}
