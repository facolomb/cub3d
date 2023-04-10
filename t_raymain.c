/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_raymain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:46:57 by mravera           #+#    #+#             */
/*   Updated: 2023/04/10 17:38:34 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

double	t_get_dist(double dir, t_data *data)
{
	if ((dir >= 0) && (dir < 90))
		return (get_dist_ne(dir, data));
	else if ((dir >= 90) && (dir < 180))
		return (get_dist_nw(dir, data));
	else if ((dir >= 180) && (dir < 270))
		return (get_dist_sw(dir, data));
	else if ((dir >= 270) && (dir < 360))
		return (get_dist_se(dir, data));
	else
		printf("Error\nWrong dir value.\n");
	return (-1);
}

int	t_whatis(double x, double y, t_data *data)
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
