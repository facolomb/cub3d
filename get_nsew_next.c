/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nsew_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 03:13:59 by mravera           #+#    #+#             */
/*   Updated: 2023/04/14 15:04:58 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "test.h"

int	get_next_ne(double dir, t_data *data)
{
	double	a[2];
	double	b[2];
	double	theta;

	theta = dir * M_PI / 180;
	a[0] = data->ray[0] + 0.000000001;
	a[1] = data->ray[1] - 0.000000001;
	b[0] = a[0];
	b[1] = a[1];
	a[1] = a[1] - (tan(theta) * (ceil(a[0]) - a[0]));
	a[0] = ceil(a[0]);
	b[0] = ((b[1] - floor(b[1])) / tan(theta)) + b[0];
	b[1] = floor(b[1]);
	if (walldistance(data, a[0], a[1]) < walldistance(data, b[0], b[1]))
	{
		data->ray[0] = a[0];
		data->ray[1] = a[1];
	}
	else
	{
		data->ray[0] = b[0];
		data->ray[1] = b[1];
	}
	return (0);
}

int	get_next_nw(double dir, t_data *data)
{
	double	a[2];
	double	b[2];
	double	theta;

	theta = dir * M_PI / 180;
	a[0] = data->ray[0] - 0.000000001;
	a[1] = data->ray[1] - 0.000000001;
	b[0] = a[0];
	b[1] = a[1];
	a[1] = a[1] - (tan(2 * M_PI - theta) * (a[0] - floor(a[0])));
	a[0] = floor(a[0]);
	b[0] = -((b[1] - floor(b[1])) / tan(2 * M_PI - theta)) + b[0];
	b[1] = floor(b[1]);
	if (walldistance(data, a[0], a[1]) < walldistance(data, b[0], b[1]))
	{
		data->ray[0] = a[0];
		data->ray[1] = a[1];
	}
	else
	{
		data->ray[0] = b[0];
		data->ray[1] = b[1];
	}
	return (0);
}

int	get_next_sw(double dir, t_data *data)
{
	double	a[2];
	double	b[2];
	double	theta;

	theta = dir * M_PI / 180;
	a[0] = data->ray[0] - 0.000000001;
	a[1] = data->ray[1] + 0.000000001;
	b[0] = a[0];
	b[1] = a[1];
	a[1] = (tan(theta) * (a[0] - floor(a[0]))) + a[1];
	a[0] = floor(a[0]);
	b[0] = -((ceil(b[1]) - b[1]) / tan(2 * M_PI + theta)) + b[0];
	b[1] = ceil(b[1]);
	if (walldistance(data, a[0], a[1]) < walldistance(data, b[0], b[1]))
	{
		data->ray[0] = a[0];
		data->ray[1] = a[1];
	}
	else
	{
		data->ray[0] = b[0];
		data->ray[1] = b[1];
	}
	return (0);
}

int	get_next_se(double dir, t_data *data)
{
	double	a[2];
	double	b[2];
	double	theta;

	theta = dir * M_PI / 180;
	a[0] = data->ray[0] + 0.000000001;
	a[1] = data->ray[1] + 0.000000001;
	b[0] = a[0];
	b[1] = a[1];
	a[1] = a[1] - (tan(theta) * (ceil(a[0]) - a[0]));
	a[0] = ceil(a[0]);
	b[0] = ((ceil(b[1]) - b[1]) / tan(0 - theta)) + b[0];
	b[1] = ceil(b[1]);
	if (walldistance(data, a[0], a[1]) < walldistance(data, b[0], b[1]))
	{
		data->ray[0] = a[0];
		data->ray[1] = a[1];
	}
	else
	{
		data->ray[0] = b[0];
		data->ray[1] = b[1];
	}
	return (0);
}
