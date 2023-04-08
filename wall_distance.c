/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:18:29 by mravera           #+#    #+#             */
/*   Updated: 2023/04/08 17:13:05 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

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
