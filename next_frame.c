/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:02:54 by mravera           #+#    #+#             */
/*   Updated: 2023/04/14 15:30:26 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "test.h"

int	next_frame(t_data *data)
{
	t_imgdata	ima;
	int			x;

	x = 0;
	ima.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	ima.addr = mlx_get_data_addr(ima.img, &ima.bpp, &ima.l_length, &ima.endian);
	while (x < WIN_WIDTH)
	{
		draw_col(x, &ima, data);
		x ++;
	}
	printf("p_dir = %lf\n", data->p_dir);
	printf("px = %lf\npy = %lf\n", data->player_x, data->player_y);
	mlx_put_image_to_window(data->mlx, data->win, ima.img, 0, 0);
	mlx_destroy_image(data->mlx, ima.img);
	return (0);
}

int	draw_col(int x, t_imgdata *img, t_data *data)
{
	int		y;
	double	dist;
	double	col_size;

	y = 0;
	dist = (t_get_dist(dblmod(data->p_dir - get_rel_dir(x)), data));
	col_size = WALL_RATIO * WIN_HEIGHT
		/ dist;
	if (col_size > WIN_HEIGHT)
		while (y < WIN_HEIGHT)
			my_pixel_put(img, x, y++, str_color(NULL));
	else
	{
		while (y < (WIN_HEIGHT - col_size) / 2)
			my_pixel_put(img, x, y++, data->c_color);
		while (y < (col_size + ((WIN_HEIGHT - col_size) / 2)))
			my_pixel_put(img, x, y++, str_color(NULL));
		while (y < WIN_HEIGHT)
			my_pixel_put(img, x, y++, data->f_color);
	}
	return (0);
}

double	get_rel_dir(int x)
{
	double	theta;

	if (x < 0 || x >= WIN_WIDTH)
		return (1);
	if (x < (WIN_WIDTH / 2))
		theta = -(FOV / 2 - ((double)x / WIN_WIDTH * FOV));
	else
		theta = (((double)x - (WIN_WIDTH / 2)) / WIN_WIDTH * FOV);
	return (theta);
}
