/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_grow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:25:59 by htkachuk          #+#    #+#             */
/*   Updated: 2017/11/22 21:39:37 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_sort_grow(int *arr, int len)
{
	int		i;
	int		j;
	int		temp;

	if (!arr)
		return (0);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}
