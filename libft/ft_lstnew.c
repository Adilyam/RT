/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:20:31 by htkachuk          #+#    #+#             */
/*   Updated: 2017/11/17 17:20:34 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;
	void	*content_1;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		if (content == NULL)
		{
			tmp->content = NULL;
			tmp->content_size = 0;
		}
		else
		{
			content_1 = ft_memalloc(content_size);
			ft_memcpy(content_1, content, content_size);
			tmp->content = content_1;
			tmp->content_size = content_size;
		}
		tmp->next = NULL;
		return (tmp);
	}
	return (0);
}
