/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:52:05 by mravera           #+#    #+#             */
/*   Updated: 2023/04/13 02:42:01 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	p_dirup(t_data *data)
{
	data->p_dir += DIR_STEP;
	data->p_dir = (data->p_dir % 360);
	return (0);
}

int	p_dirdown(t_data *data)
{
	data->p_dir -= DIR_STEP;
	if (data->p_dir < 0)
		data->p_dir = (360 + (data->p_dir % 360));
	return (0);
}

int	cb_mouse(int x, int y, t_data *data)
{
	int	a;

	(void)y;
	a = WIN_WIDTH / 2;
	if (data->mouse_h)
	{
		data->p_dir -= ((x - a) * MOUSE_SENS);
		if (data->p_dir < 0)
			data->p_dir = (360 + (data->p_dir % 360));
		else
			data->p_dir = (data->p_dir % 360);
		mlx_mouse_move(data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
	return (0);
}
