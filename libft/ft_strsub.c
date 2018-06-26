/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:21:56 by htkachuk          #+#    #+#             */
/*   Updated: 2017/11/10 11:21:58 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	count;

	count = 0;
	if (!s)
		return (NULL);
	s1 = (char*)malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (0);
	while (count < len)
	{
		s1[count] = s[start];
		count++;
		start++;
	}
	s1[count] = '\0';
	return (s1);
}
