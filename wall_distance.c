/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:18:29 by mravera           #+#    #+#             */
/*   Updated: 2023/04/07 15:58:13 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

double	walldistance(t_data *data, double x, double y)
{
	double	a;
	double	b;
	double	c;

	printf("\nTEST\n");
	printf("x  = %lf, y  = %lf\n", x, y);
	printf("px = %lf, py = %lf\n", data->player_x, data->player_y);
	a = x - data->player_x;
	b = y - data->player_y;
	printf("a = %lf\nb = %lf\n", a, b);
	c = sqrt(pow(a, 2) + pow(b, 2));
	return (c);
}
