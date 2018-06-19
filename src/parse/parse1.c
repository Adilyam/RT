/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 13:31:52 by atilegen          #+#    #+#             */
/*   Updated: 2018/06/16 13:31:53 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		check_objects_part(char *str, int i, t_all *ev)
{
	if (!ft_strnequ(str + i, "\"objects\"", 9))
		error_end("Not an \"objects\" object");
	i += 9;
	spaces(str, &i);
	check_symbol(str, &i, ':');
	spaces(str, &i);
	check_symbol(str, &i, '[');
	spaces(str, &i);
	check_symbol(str, &i, '{');
	spaces(str, &i);
	ev->index = 0;
	i = check_exact_object(str, i, ev);
	return (i);
}

int		check_lights_part(char *str, int i, t_all *ev)
{
	if (!ft_strnequ(str + i, "\"lights\"", 8))
		error_end("Not an \"lights\" object");
	i += 8;
	spaces(str, &i);
	check_symbol(str, &i, ':');
	spaces(str, &i);
	check_symbol(str, &i, '[');
	spaces(str, &i);
	check_symbol(str, &i, '{');
	spaces(str, &i);
	ev->index = 0;
	i = check_exact_light(str, i, ev);
	return (i);
}

int		check_camera_part(char *str, int i, t_all *ev)
{
	if (!ft_strnequ(str + i, "\"camera\"", 8))
		error_end("Not an \"camera\" object");
	i += 8;
	spaces(str, &i);
	check_symbol(str, &i, ':');
	spaces(str, &i);
	check_symbol(str, &i, '{');
	spaces(str, &i);
	i = check_exact_camera(str, i, ev);
	return (i);
}

int check_all(char *str, t_all *ev)
{
	int i;  

	i = 0;
	spaces(str, &i);
	check_symbol(str, &i, '{');
	spaces(str, &i);
	if (!ft_strnequ(str + i, "\"scene\"", 7))
		error_end("Nu kak by tut tochno ne scene");
	i += 7;
	universal_check(str, &i);
	check_symbol(str, &i, '{');
	spaces(str, &i);
	i = check_scene(str, i, ev);
	spaces(str, &i);
	check_symbol(str, &i, '}');
	spaces(str, &i);
	check_symbol(str, &i, ',');
	spaces(str, &i);
	i = check_objects_part(str, i, ev);
	ft_putendl("All is super duper");
	spaces(str, &i); 
	i = check_lights_part(str, i, ev);
	ft_putendl("All is super duper 2");
	spaces(str, &i);
	i = check_camera_part(str, i, ev);
	return (1);
}

int     parse_check(t_all *ev)
{
	char *line;
	int ret;
	char buf[1];
	char str[BUF_SIZE];
	int j;

	j = 0;
	if (ev->fd >= 0)
	{
		while (read(ev->fd, buf, 1) > 0 && j < BUF_SIZE)
			str[j++] = buf[0];
		str[j] = '\0';
		close(ev->fd);
		if (!(check2(str)))
			error_end("nepravil'nye brackets brataaaaaahn");
	}
	if (check_all(str, ev))
		return (1);
	return (0);
}
