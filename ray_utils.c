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

#include "parsing.h"
#include "test.h"

double	dblmod(double a)
{
	double	b;

	b = 360;
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

int	posmod(int a, int b)
{
	int	x;

	x = a % b;
	if (x >= 0)
		return (x);
	else
		return (b + x);
}
