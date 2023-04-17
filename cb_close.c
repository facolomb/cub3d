/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:41:56 by mravera           #+#    #+#             */
/*   Updated: 2023/04/15 05:42:34 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cb_close(t_data *data)
{
	printf("Closing...");
	mlx_destroy_window(data->mlx, data->win);
	free_data(data);
	exit(EXIT_SUCCESS);
	return (0);
}
