/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nsew_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:08:16 by mravera           #+#    #+#             */
/*   Updated: 2023/04/13 04:16:28 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

double	get_dist_ne(double dir, t_data *data)
{
	double	resa;

	get_border_ne(dir, data);
	while (t_whatis(data->ray[0], data->ray[1], data) == 0)
		get_next_ne(dir, data);
	resa = walldistance(data, data->ray[0], data->ray[1]);
	return (resa);
}

double	get_dist_nw(double dir, t_data *data)
{
	double	resa;

	get_border_nw(dir, data);
	while (t_whatis(data->ray[0], data->ray[1], data) == 0)
		get_next_nw(dir, data);
	resa = walldistance(data, data->ray[0], data->ray[1]);
	return (resa);
}

double	get_dist_sw(double dir, t_data *data)
{
	double	resa;

	get_border_sw(dir, data);
	while (t_whatis(data->ray[0], data->ray[1], data) == 0)
		get_next_sw(dir, data);
	resa = walldistance(data, data->ray[0], data->ray[1]);
	return (resa);
}

double	get_dist_se(double dir, t_data *data)
{
	double	resa;

	get_border_se(dir, data);
	while (t_whatis(data->ray[0], data->ray[1], data) == 0)
		get_next_se(dir, data);
	resa = walldistance(data, data->ray[0], data->ray[1]);
	return (resa);
}

double	fisheye_d(double rel_dir)
{
	double	res;
	double	theta;

	theta = rel_dir * M_PI / 180;
	res = SCREEN_DIST / cos(theta);
	return (res);
}
