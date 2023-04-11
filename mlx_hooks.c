/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:31:26 by mravera           #+#    #+#             */
/*   Updated: 2023/04/12 00:13:43 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	cb_close(int keycode, t_data *data)
{
	(void)keycode;
	mlx_destroy_window(data->mlx, data->win);
	free_data(data);
	exit(EXIT_SUCCESS);
	return (0);
}
