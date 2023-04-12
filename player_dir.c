/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:52:05 by mravera           #+#    #+#             */
/*   Updated: 2023/04/12 23:00:34 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	p_dirup(t_data *data)
{
	data->p_dir += DIR_STEP;
	data->p_dir = data->p_dir % 360;
	return (1);
}

int	p_dirdown(t_data *data)
{
	data->p_dir -= DIR_STEP;
	if (data->p_dir < 0)
		data->p_dir = 360 + (data->p_dir % 360);
	return (1);
}
