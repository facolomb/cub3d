/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:59:39 by mravera           #+#    #+#             */
/*   Updated: 2023/04/15 05:13:51 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freetab(char **tab)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return ;
}

int	free_data(t_data *data)
{
	if (data->no != NULL)
		free(data->no);
	if (data->so != NULL)
		free(data->so);
	if (data->ea != NULL)
		free(data->ea);
	if (data->we != NULL)
		free(data->we);
	if (data->map != NULL)
		freetab(data->map);
	if (data->im_no.img != NULL)
		mlx_destroy_image(data->mlx, data->im_no.img);
	if (data->im_so.img != NULL)
		mlx_destroy_image(data->mlx, data->im_so.img);
	if (data->im_we.img != NULL)
		mlx_destroy_image(data->mlx, data->im_we.img);
	if (data->im_ea.img != NULL)
		mlx_destroy_image(data->mlx, data->im_ea.img);
	return (0);
}

int	disp_data(t_data *data)
{
	printf("\n\n--------------DATAS--------------\n");
	printf("no = %p\n", data->im_no.addr);
	printf("so = %p\n", data->im_so.addr);
	printf("ea = %p\n", data->im_ea.addr);
	printf("we = %p\n", data->im_we.addr);
	printf("c = %d\n", data->c_color);
	printf("f = %d\n\n", data->f_color);
	printf("player x = %lf\n       y = %lf\n", data->player_x, data->player_y);
	printf("     dir = %lf\n", data->p_dir);
	return (0);
}
