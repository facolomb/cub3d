/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:31:26 by mravera           #+#    #+#             */
/*   Updated: 2023/04/15 05:41:35 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	cb_keypress(int keycode, t_data *data)
{
	if (keycode == ESC)
		cb_close(data);
	else if (keycode == W || keycode == ARROWUP)
		p_up(data);
	else if (keycode == S || keycode == ARROWDOWN)
		p_dw(data);
	else if (keycode == A)
		p_left(data);
	else if (keycode == D)
		p_right(data);
	else if (keycode == Q || keycode == ARROWLEFT)
		p_dirup(data);
	else if (keycode == E || keycode == ARROWRIGHT)
		p_dirdown(data);
	return (0);
}

int	cb_mousepress(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 3)
	{
		if (!data->mouse_h)
		{
			mlx_mouse_hide();
			data->mouse_h = 1;
		}
		else
		{
			mlx_mouse_show();
			data->mouse_h = 0;
		}
	}
	return (0);
}

int	mlx_set_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, cb_keypress, data);
	mlx_hook(data->win, 17, 1L << 2, cb_close, data);
	mlx_hook(data->win, 6, 1L << 6, cb_mouse, data);
	mlx_hook(data->win, 4, 1L << 2, cb_mousepress, data);
	return (0);
}
