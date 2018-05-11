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

#include "RTv1.h"

t_vector	vector_plus_const(t_vector A, double b)
{
	A.x = A.x + b;
	A.y = A.y + b;
	A.z = A.z + b;
	return (A);
}

t_vector	vector_minus_const(t_vector A, double b)
{
	A.x = A.x - b;
	A.y = A.y - b;
	A.z = A.z - b;
	return (A);
}

t_vector	vector_multy_const(t_vector A, double b)
{
	A.x = A.x * b;
	A.y = A.y * b;
	A.z = A.z * b;
	return (A);
}

t_vector	vector_div_const(t_vector A, double b)
{
	A.x = A.x / b;
	A.y = A.y / b;
	A.z = A.z / b;
	return (A);
}
