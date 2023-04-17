/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:30:27 by mravera           #+#    #+#             */
/*   Updated: 2023/04/15 05:47:53 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '1' || str[i] == '0')
		return (1);
	else
		return (0);
}

int	is_mapkey(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == '1' || c == '0' || c == ' ')
		return (1);
	else
		return (0);
}

int	check_strmap(char *str)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (!is_mapkey(str[i]))
			return (-1);
		if (str[i] == 'N' || str[i] == 'S'
			|| str[i] == 'E' || str[i] == 'W')
			x ++;
		i ++;
	}
	return (x);
}

int	print_maperr(t_data *data)
{
	printf("\nError\nWrong char in map.\n");
	data->dead = 1;
	return (-1);
}

int	print_nsew(int x, t_data *data)
{
	if (x == 0)
		printf("Error\nNo NSEW char in map.\n");
	else
		printf("Error\nToo many NSEW char in map [%d]\n", x);
	data->dead = 1;
	return (0);
}
