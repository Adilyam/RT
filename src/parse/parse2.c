/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 15:20:07 by atilegen          #+#    #+#             */
/*   Updated: 2018/06/17 15:20:08 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int check_exact_object(char *str, int i, t_all *ev)
{
	int check[7];
	int *res;

	ev->index++;
	spaces(str, &i);
	if (!(ft_strnequ(str + i, "\"position\"", 10) || ft_strnequ(str + i, "\"size\"", 6) || ft_strnequ(str + i, "\"name\"", 6) || ft_strnequ(str + i, "\"color\"", 7) || ft_strnequ(str + i, "\"specularity\"", 13) || ft_strnequ(str + i, "\"tan\"", 5) || ft_strnequ(str + i, "\"direction\"", 11)))
		error_end("Wrong input");
	if ((ft_strnequ(str + i, "\"size\"", 6)))
	{
		i += 6;
		universal_check(str, &i);
		ev->figure[ev->index].radius = check_if_input_number(&i, str);
	}
	else if ((ft_strnequ(str + i, "\"position\"", 10)))
	{
		i += 10;
		universal_check(str, &i);
		check_symbol(str, &i, '[');
		spaces(str, &i);
		res = check_if_3digit_input(str, &i);
		ev->figure[ev->index].centre.x = res[0];
		ev->figure[ev->index].centre.y = res[1];
		ev->figure[ev->index].centre.z = res[2];
	}
	else if ((ft_strnequ(str + i, "\"name\"", 6)))
	{
		i += 6;
		universal_check(str, &i);
		check_objects_string(str, &i, &ev->figure[ev->index]);
	}
	else if (ft_strnequ(str + i, "\"specularity\"", 13))
	{
		i += 13;
		universal_check(str, &i);
		ev->figure[ev->index].specular = check_if_input_float(&i, str);
	}
	else if ((ft_strnequ(str + i, "\"color\"", 7)))
	{
		i += 7;
		universal_check(str, &i);
		check_symbol(str, &i, '[');
		spaces(str, &i);
		res = check_if_3digit_input(str, &i);
		ev->figure[ev->index].color.chanels.r = res[0];
		ev->figure[ev->index].color.chanels.g = res[1];
		ev->figure[ev->index].color.chanels.b = res[2];
	}
	spaces(str, &i);
	if (str[i] == ',')
		i = check_exact_object(str, i + 1, ev);
	else if (str[i++] == '}')
	{
		spaces(str, &i);
		if (str[i] == ',') //все обнулять типа или обджект ++
		{
			i++;
			spaces(str, &i);
			if (str[i++] == '{')
			{
				// printf("%s=======\n", str + i);
				i = check_exact_object(str, i, ev);
			}
		}
		else if (check_if_end(str, &i))
			error_end("seems to be no lights in your scene");
	}
	else
	{
		printf("%s", str + i);
		error_end("chto-to levoe obj");
	}
	return (i);
}

int check_exact_light(char *str, int i, t_all *ev)
{
	int check[7];

	spaces(str, &i);
	// printf("check %s\n", str + i);
	if (!(ft_strnequ(str + i, "\"intensity\"", 11) || ft_strnequ(str + i, "\"position\"", 10) || ft_strnequ(str + i, "\"type\"", 6)))
		error_end("Wrong input");
	if (ft_strnequ(str + i, "\"intensity\"", 11))
	{
		i += 11;
		universal_check(str, &i);
		check_if_input_float(&i, str);
	}
	else if ((ft_strnequ(str + i, "\"position\"", 10)))
	{
		i += 10;
		universal_check(str, &i);
		check_symbol(str, &i, '[');
		spaces(str, &i);
		check_if_3digit_input(str, &i);
	}
	else if ((ft_strnequ(str + i, "\"type\"", 6)))
	{
		i += 6;
		universal_check(str, &i);
		check_light_string(str, &i);
	}
	spaces(str, &i);
	if (str[i] == ',')
		i = check_exact_light(str, i + 1, ev);
	else if (str[i++] == '}')
	{
		spaces(str, &i);
		if (str[i] == ',') //все обнулять типа или обджект ++
		{
			i++;
			spaces(str, &i);
			if (str[i++] == '{')
			{
				// printf("%s=======\n", str + i);
				i = check_exact_light(str, i, ev);
			}
		}
		else if (check_if_end(str, &i))
			error_end("seems to be no camera in your scene");
	}
	else
		error_end("chto-to levoe_lgt");
	return (i);
}

int check_exact_camera(char *str, int i, t_all *ev)
{
	int check[7];

	spaces(str, &i);
	// printf("check %s", str + i);
	if (!(ft_strnequ(str + i, "\"direction\"", 11) || ft_strnequ(str + i, "\"position\"", 10)))
		error_end("Wrong input");
	if (ft_strnequ(str + i, "\"direction\"", 11))
	{
		i += 11;
		universal_check(str, &i);
		check_symbol(str, &i, '[');
		spaces(str, &i);
		check_if_3digit_input(str, &i);
	}
	else if ((ft_strnequ(str + i, "\"position\"", 10)))
	{
		i += 10;
		universal_check(str, &i);
		check_symbol(str, &i, '[');
		spaces(str, &i);
		check_if_3digit_input(str, &i);
	}
	spaces(str, &i);
	// printf("%s\n", str + i);
	if (str[i] == ',')
		i = check_exact_camera(str, i + 1, ev);
	else if (str[i++] == '}')
	{
		spaces(str, &i);
		if (str[i] == '}') //все обнулять типа или обджект ++
		{
			i++;
			spaces(str, &i);
			if (str[i] != '\0')
				printf("Ty chudak");
		}
	}
	else
		error_end("chto-to levoe_cam");
	return (i);
}
