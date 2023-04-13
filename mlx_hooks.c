/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:31:26 by mravera           #+#    #+#             */
/*   Updated: 2023/04/13 02:42:38 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	cb_keypress(int keycode, t_data *data)
{
	if (keycode == ESC)
		cb_close(data);
	else if (keycode == A)
		p_dirup(data);
	else if (keycode == D)
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
