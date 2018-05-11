/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <htkachuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:13:47 by htkachuk          #+#    #+#             */
/*   Updated: 2017/11/03 16:42:07 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(int i, const char *haystack,
	const char *needle)
{
	int	m;
	int	j;

	j = 0;
	m = 1;
	while (needle[j])
	{
		if (haystack[i] != needle[j])
		{
			m = 0;
			break ;
		}
		i++;
		j++;
	}
	return (m);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			m = check(i, haystack, needle);
			if (m)
				return ((char*)haystack + i);
		}
		i++;
	}
	return (NULL);
}
