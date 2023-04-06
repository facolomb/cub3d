/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nsew_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:08:16 by mravera           #+#    #+#             */
/*   Updated: 2023/04/07 01:52:59 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

double	get_dist_ne(double dir, t_data *data)
{
	double	res;
	double	a[2];
	double	b[2];

	a[0] = data->player_x;
	a[1] = data->player_y;
	while (t_whatis(a[0], a[1], data) == '0')
	{
		a[1] = a[1] + (tan(dir * M_PI / 180) * ceil(a[0]) - a[0]);
		a[0] = ceil(a[0]);
	}
	return (res);
}
