/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:56:01 by mravera           #+#    #+#             */
/*   Updated: 2023/04/15 03:58:20 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

void	my_pixel_put(t_imgdata *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
	return ;
}

int	pixel_get(t_imgdata *data, double x_ratio, double y_ratio)
{
	char	*dst;
	int		x;
	int		y;

	x = floor(x_ratio * data->img_width);
	y = floor(y_ratio * data->img_height);
	if ((x < 0) || (x >= data->img_width)
		|| (y < 0) || (y >= data->img_width))
	{
		//printf("Error\npixel_get() out of limit.");
		return (0);
	}
	dst = data->addr + (y * data->l_length + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}
