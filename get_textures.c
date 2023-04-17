/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:49:23 by mravera           #+#    #+#             */
/*   Updated: 2023/04/15 03:47:06 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(int y, double col_s, t_data *data)
{
	if (!data->ray[0] || (data->ray[0] / round(data->ray[0])) == 1)
	{
		if (data->player_x < data->ray[0])
			return (pixel_get(&data->im_we, get_x(data), get_y(y, col_s)));
		else
			return (pixel_get(&data->im_ea, get_x(data), get_y(y, col_s)));
	}
	else if (!data->ray[1] || (data->ray[1] / round(data->ray[1])) == 1)
	{
		if (data->player_y < data->ray[1])
			return (pixel_get(&data->im_no, get_x(data), get_y(y, col_s)));
		else
			return (pixel_get(&data->im_so, get_x(data), get_y(y, col_s)));
	}
	return (0);
}

double	get_x(t_data *data)
{
	double	res;

	if ((data->ray[0] / round(data->ray[0])) == 1)
	{
		if (data->player_x < data->ray[0])
			res = (data->ray[1] - floor(data->ray[1]));
		else
			res = (ceil(data->ray[1]) - data->ray[1]);
	}
	else if ((data->ray[1] / round(data->ray[1])) == 1)
	{
		if (data->player_y < data->ray[1])
			res = (ceil(data->ray[0]) - data->ray[0]);
		else
			res = (data->ray[0] - floor(data->ray[0]));
	}
	else
		res = 0;
	return (res);
}

double	get_y(int y, double col_s)
{
	double	res;

	res = ((y - ((WIN_HEIGHT - col_s) / 2)) / col_s);
	return (res);
}
