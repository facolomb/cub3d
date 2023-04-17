/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:52:05 by mravera           #+#    #+#             */
/*   Updated: 2023/04/13 05:15:28 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	p_dirup(t_data *data)
{
	data->p_dir += DIR_STEP;
	data->p_dir = dblmod(data->p_dir);
	return (0);
}

int	p_dirdown(t_data *data)
{
	data->p_dir -= DIR_STEP;
	data->p_dir = dblmod(data->p_dir);
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
		data->p_dir = dblmod(data->p_dir);
		mlx_mouse_move(data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
	return (0);
}
