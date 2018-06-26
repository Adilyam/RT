/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <htkachuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:13:58 by htkachuk          #+#    #+#             */
/*   Updated: 2017/11/03 16:58:19 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checker(size_t i, const char *haystack,
	const char *needle, size_t len)
{
	int	j;

	j = 0;
	while (needle[j] == haystack[i] && i < len)
	{
		i++;
		j++;
		if (needle[j] == '\0')
			return (1);
	}
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
			if (checker(i, haystack, needle, len))
				return ((char*)haystack + i);
		i++;
	}
	return (NULL);
}
