/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:19:30 by htkachuk          #+#    #+#             */
/*   Updated: 2017/11/10 13:19:32 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*copy(int m, int len, char *dst, char const *s)
{
	int	i;

	i = 0;
	while (m < len + 1)
	{
		dst[i] = s[m];
		i++;
		m++;
	}
	dst[i] = '\0';
	return (dst);
}

char			*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	int		len_1;
	char	*dst;
	int		m;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	len_1 = len;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	m = i;
	len--;
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && len > i)
	{
		i++;
		len--;
	}
	dst = (char*)malloc(sizeof(char) * (len_1 - i + 1));
	if (!dst)
		return (0);
	return (copy(m, len, dst, s));
}
