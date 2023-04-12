/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:31:26 by mravera           #+#    #+#             */
/*   Updated: 2023/04/12 22:50:51 by mravera          ###   ########.fr       */
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
