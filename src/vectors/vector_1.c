/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:10:51 by htkachuk          #+#    #+#             */
/*   Updated: 2018/05/11 15:10:54 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	vector_plus_const(t_vector a, double b)
{
	a.x = a.x + b;
	a.y = a.y + b;
	a.z = a.z + b;
	return (a);
}

t_vector	vector_minus_const(t_vector a, double b)
{
	a.x = a.x - b;
	a.y = a.y - b;
	a.z = a.z - b;
	return (a);
}

t_vector	vector_multy_const(t_vector a, double b)
{
	a.x = a.x * b;
	a.y = a.y * b;
	a.z = a.z * b;
	return (a);
}

t_vector	vector_div_const(t_vector a, double b)
{
	a.x = a.x / b;
	a.y = a.y / b;
	a.z = a.z / b;
	return (a);
}
