/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 20:14:26 by htkachuk          #+#    #+#             */
/*   Updated: 2017/11/03 20:14:31 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	int				j;
	unsigned char	*s1_1;
	unsigned char	*s2_1;

	s1_1 = (unsigned char*)s1;
	s2_1 = (unsigned char*)s2;
	i = 0;
	j = 0;
	while (s1_1[i] || s2_1[i])
	{
		if (s1_1[i] != s2_1[i])
			return (s1_1[i] - s2_1[i]);
		i++;
	}
	return (0);
}
