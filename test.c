/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:45:38 by mravera           #+#    #+#             */
/*   Updated: 2023/04/15 05:54:09 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_data		data;
	int			i;

	i = 0;
	data = (t_data){0};
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (argc > 1)
		parsing(argc, argv, &data);
	else
	{
		printf("Error\nNeed a .cub configuration file as argument\n");
		data.dead = 1;
	}
	if (data.dead == 1)
		cb_close(&data);
	disp_data(&data);
	mlx_set_hooks(&data);
	mlx_loop_hook(data.mlx, next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
