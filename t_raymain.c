/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_raymain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:46:57 by mravera           #+#    #+#             */
/*   Updated: 2023/04/06 02:29:18 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

/*
float	t_getdist(float dir, float x, float y, t_data *data)
{
	float	res;

	return (res);
}
*/

int	t_whatis(float x, float y, t_data *data)
{
	if ((x >= data->mapmx) || (y >= data->mapmy)
		|| x <= 0 || y <= 0)
		return (-1);
	if ((x / floor(x)) == 1)
	{
		if (data->map[(int)floor(y)][((int)x - 1)] == '1'
			|| data->map[(int)floor(y)][(int)x] == '1')
			return (1);
	}
	if ((y / floor(y)) == 1)
	{
		if (data->map[(int)y - 1][(int)floor(x)] == '1'
			|| data->map[(int)y][(int)floor(x)] == '1')
			return (1);
	}
	if ((x / floor(x) == 1) && (y / floor(y) == 1))
		if (data->map[(int)y - 1][(int)x - 1] == '1')
			return (1);
	return (0);
}
