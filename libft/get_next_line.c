/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:58:16 by htkachuk          #+#    #+#             */
/*   Updated: 2018/01/11 20:58:19 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	multiple_file_descriptor(t_list **current, t_list **list, int fd)
{
	t_list	*for_fd;

	while (*current && ((*current)->content_size != (size_t)fd))
		*current = (*current)->next;
	if (!(*current))
	{
		if (!(for_fd = (t_list*)malloc(sizeof(t_list))))
			return (1);
		for_fd->content = ft_strnew(BUFF_SIZE);
		for_fd->content_size = fd;
		ft_lstadd(list, for_fd);
		*current = *list;
	}
	return (0);
}

static void	ft_free_midle(t_list **list, t_list *current)
{
	t_list	*prev;

	prev = *list;
	if (prev == current)
	{
		*list = current->next;
	}
	else
	{
		while (prev->next != current)
			prev = prev->next;
		prev->next = current->next;
	}
	free(current);
}

static int	ft_check(char **line, t_list *current, char *str, t_list **list)
{
	int		k;

	if (!(current->content) || *((char*)current->content) == '\0')
	{
		ft_free_midle(list, current);
		return (0);
	}
	if (!(ft_strchr((char *)current->content, '\n')))
		return (3);
	k = (int)(ft_strchr((char*)current->content, '\n')
		- (char*)current->content);
	*line = ft_strsub((char*)current->content, 0, k);
	str = ft_strsub((char*)current->content, (k + 1),
		(ft_strlen(current->content) - k));
	ft_memdel(&current->content);
	current->content = str;
	return (1);
}

static int	ft_r_ch(t_list **current, int fd, char **line, t_list **list)
{
	char	*temp;
	int		k;
	int		ret;
	char	*str;

	str = ft_strnew(BUFF_SIZE);
	ret = 3;
	while (ret == 3 && (k = read(fd, str, BUFF_SIZE)) > 0)
	{
		temp = (*current)->content;
		(*current)->content = ft_strjoin((char*)(*current)->content, str);
		ft_bzero(str, BUFF_SIZE);
		free(temp);
		ret = ft_check(line, *current, str, list);
	}
	if (ret == 3 && (*line = (char*)(*current)->content))
		if ((ret = ft_check(line, *current, str, list)) == 3)
		{
			ret = 1;
			(*current)->content = "\0";
		}
	free(str);
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	t_list			*current;

	if (fd < 0 || fd > 4864 || BUFF_SIZE < 0 || !line
		|| (read(fd, line, 0)) == -1)
		return (-1);
	current = list;
	if (multiple_file_descriptor(&current, &list, fd))
		return (-1);
	return (ft_r_ch(&current, fd, line, &list));
}
