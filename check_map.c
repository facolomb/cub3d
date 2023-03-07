/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:50:06 by mravera           #+#    #+#             */
/*   Updated: 2023/03/07 16:30:07 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	check_map(t_data *data)
{
	char	**m;
	int		i;
	int		x;

	x = 0;
	i = 0;
	m = data->map;
	while (m[i])
	{
		if (check_strmap(m[i]) < 0)
			return (print_maperr());
		else
			x += check_strmap(m[i]);
		i ++;
	}
	if (x >= 0 && x != 1)
		return (print_nsew(x));
/*
	if (is_map_closed(m))
		return (1);
	*/
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
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			x ++;
		i ++;
	}
	return (x);
}

int	print_maperr(void)
{
	printf("\nError\nWrong char in map.\n");
	return (-1);
}

int	print_nsew(int x)
{
	if (x == 0)
		printf("Error\nNo NSEW char in map.\n");
	else
		printf("Error\nToo many NSEW char in map [%d]\n", x);
	return (0);
}
