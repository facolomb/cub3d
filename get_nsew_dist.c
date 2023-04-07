/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nsew_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:08:16 by mravera           #+#    #+#             */
/*   Updated: 2023/04/07 18:44:14 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

double	get_dist_ne(double dir, t_data *data)
{
	double	resa;
	double	resb;
	double	a[2];
	double	b[2];

	a[0] = data->player_x;
	a[1] = data->player_y;
	b[0] = a[0];
	b[1] = b[1];
	/*
	while (t_whatis(a[0], a[1], data) == '0')
	{
		a[1] = a[1] - (tan(dir * M_PI / 180) * (ceil(a[0]) - a[0]));
		a[0] = ceil(a[0]);
	}
	*/
	printf("player pos = %lf\n            %lf\n", a[0], a[1]);
	a[1] = a[1] - (tan(dir * M_PI / 180) * (ceil(a[0]) - a[0]));
	a[0] = ceil(a[0]);
	b[0] = ((b[1] - floor(b[1])) / tan(dir * M_PI / 180)) + b[0];
	b[1] = floor(b[1]);
	printf("t_whatis a = %d\n", t_whatis(a[0], a[1], data));
	printf("t_whatis b = %d\n", t_whatis(b[0], b[1], data));
	printf("ray a goes to %lf\n            %lf\n", a[0], a[1]);
	printf("ray b goes to %lf\n            %lf\n", b[0], b[1]);
	printf("ray a length is %lf\n", walldistance(data, a[0], a[1]));
	printf("ray b length is %lf\n", walldistance(data, b[0], b[1]));
	resa = walldistance(data, a[0], a[1]);
	resb = walldistance(data, b[0], b[1]);
	if (resa < resb)
		return (resa);
	return (resb);
}

/*
double	get_dist_ne(double dir, t_data *data)
{
	double	res;
	double	a[2];
	//double	b[2];

	a[0] = data->player_x;
	a[1] = data->player_y;
	while (t_whatis(a[0], a[1], data) == '0')
	{
		a[1] = a[1] - (tan(dir * M_PI / 180) * (ceil(a[0]) - a[0]));
		a[0] = ceil(a[0]);
	}
	printf("player pos = %lf\n            %lf\n", a[0], a[1]);
	a[1] = a[1] - (tan(dir * M_PI / 180) * (ceil(a[0]) - a[0]));
	a[0] = ceil(a[0]);
	printf("t_whatis = %d\n", t_whatis(a[0], a[1], data));
	printf("ray goes to %lf\n            %lf\n", a[0], a[1]);
	res = walldistance(data, a[0], a[1]);
	printf("ray length is %lf\n", res);
	return (res);
}
*/
