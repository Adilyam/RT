/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 22:45:46 by htkachuk          #+#    #+#             */
/*   Updated: 2017/11/22 22:45:48 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list *list;
	t_list *save;

	list = *alst;
	if (alst != NULL && del != NULL)
	{
		while (list != NULL)
		{
			save = list->next;
			del(list, list->content_size);
			list = save;
		}
		*alst = NULL;
	}
}
