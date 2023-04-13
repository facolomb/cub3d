/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_flood.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:46:20 by mravera           #+#    #+#             */
/*   Updated: 2023/04/08 17:13:48 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	cb_check_path(t_data *data)
{
	char	**temp;
	int		i;

	i = 0;
	if (!data->map || !data->map[0])
		return (0);
	temp = cb_dup_map(data);
	printf("\n____test cpy map____\n");
	while (data->map[i])
	{
		printf("%s\n", data->map[i]);
		i ++;
	}
	if (!cb_player_pos(data))
		printf("plyr x = %lf\nplyr y = %lf\n", data->player_x, data->player_y);
	temp[(int)data->player_y][(int)data->player_x] = '0';
	if (cb_flood(temp, data->player_x, data->player_y, data) < 0)
		printf("Error\nThe provided map seems trouee\n");
	else
		printf("Provided map seems good\n");
	freetab(temp);
	return (1);
}

char	**cb_dup_map(t_data *data)
{
	char	**res;
	int		y;

	y = 0;
	while (data->map[y])
		y ++;
	res = ft_calloc(y + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	y = 0;
	while (data->map[y])
	{
		res[y] = ft_strdup(data->map[y]);
		y ++;
	}
	res[y] = 0;
	return (res);
}

int	cb_player_pos(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				cb_set_player_pos(x, y, data->map[y][x], data);
				data->map[y][x] = '0';
				return (0);
			}
			x++;
		}
		y ++;
		x = 0;
	}
	printf("Error while looking for the player position!\n");
	return (1);
}

int	cb_set_player_pos(int x, int y, char dir, t_data *data)
{
	data->player_x = (double)x + 0.5;
	data->player_y = (double)y + 0.5;
	if (dir == 'N')
		data->p_dir = 90;
	else if (dir == 'W')
		data->p_dir = 180;
	else if (dir == 'S')
		data->p_dir = 270;
	else if (dir == 'E')
		data->p_dir = 0;
	return (0);
}

int	cb_flood(char **grid, int i, int j, t_data *data)
{
	int	y;

	y = 0;
	if (i < 0 || j < 0 || !grid[j] || !grid[j][i]
		|| ((grid[j][i] != '1') && (grid[j][i] != 'X') && (grid[j][i] != '0')))
	{
		data->check_map = -1;
		return (-1);
	}
	if (data->check_map || (grid[j][i] == '1') || (grid[j][i] == 'X'))
		return (1);
	grid[j][i] = 'X';
	cb_flood(grid, i, j + 1, data);
	cb_flood(grid, i, j - 1, data);
	cb_flood(grid, i + 1, j, data);
	cb_flood(grid, i - 1, j, data);
	return (data->check_map);
}
