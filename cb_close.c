/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:41:56 by mravera           #+#    #+#             */
/*   Updated: 2023/04/12 11:42:55 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "test.h"

int	cb_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_data(data);
	exit(EXIT_SUCCESS);
	return (0);
}