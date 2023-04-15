/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:50:06 by mravera           #+#    #+#             */
/*   Updated: 2023/04/15 05:46:18 by mravera          ###   ########.fr       */
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
			return (print_maperr(data));
		else
			x += check_strmap(m[i]);
		i ++;
	}
	if (x >= 0 && x != 1)
		return (print_nsew(x, data));
	square_map(data);
	printf("\nis_map_closed\n");
	is_map_closed(data);
	return (0);
}
