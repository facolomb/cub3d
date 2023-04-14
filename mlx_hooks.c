/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:31:26 by mravera           #+#    #+#             */
/*   Updated: 2023/04/14 01:51:52 by mravera          ###   ########.fr       */
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
	else if (keycode == A || keycode == ARROWLEFT)
		p_left(data);
	else if (keycode == D || keycode == ARROWRIGHT)
		p_right(data);
	else if (keycode == Q)
		p_dirup(data);
	else if (keycode == E)
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
