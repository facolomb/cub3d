/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:56:01 by mravera           #+#    #+#             */
/*   Updated: 2023/04/11 20:44:04 by mravera          ###   ########.fr       */
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
