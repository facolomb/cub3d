/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:42:40 by mravera           #+#    #+#             */
/*   Updated: 2023/04/13 05:21:18 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	p_up(t_data *data)
{
	double	theta;

	theta = (data->p_dir / 180 * M_PI);
	data->player_x += (cos(theta) * X_STEP);
	data->player_y += (-(sin(theta) * Y_STEP));
	return (0);
}

int	p_dw(t_data *data)
{
	double	theta;

	theta = (data->p_dir / 180 * M_PI);
	data->player_x -= (cos(theta) * X_STEP);
	data->player_y -= (-(sin(theta) * Y_STEP));
	return (0);
}
