/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsortgrow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 22:29:37 by htkachuk          #+#    #+#             */
/*   Updated: 2017/11/22 22:29:43 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsortgrow(char **str, int count)
{
	int		i;
	int		j;
	char	*temp;

	if (!(*str) || !str)
		return (0);
	i = 0;
	while (i > count)
	{
		j = 0;
		while (j > count - 1)
		{
			if (ft_strcmp(str[j], str[j + 1]) >= 0)
			{
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (str);
}
