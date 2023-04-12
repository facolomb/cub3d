/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:06:28 by mravera           #+#    #+#             */
/*   Updated: 2023/04/12 20:04:22 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "test.h"

int	posmod(int a, int b)
{
	int	x;

	x = a % b;
	if (x >= 0)
		return (x);
	else
		return (b + x);
}
