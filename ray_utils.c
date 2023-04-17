/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:06:28 by mravera           #+#    #+#             */
/*   Updated: 2023/04/13 05:04:03 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	dblmod(double a)
{
	while (a <= -360)
		a += 360;
	while (a >= 360)
		a -= 360;
	if ((a < 360) && (a > (-360)))
	{
		if (a < 0)
			return (360 + a);
		return (a);
	}
	return (a);
}

double	walldistance(t_data *data, double x, double y)
{
	double	a;
	double	b;
	double	c;

	a = x - data->player_x;
	b = y - data->player_y;
	c = sqrt(pow(a, 2) + pow(b, 2));
	return (c);
}
