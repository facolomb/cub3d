/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:50:06 by mravera           #+#    #+#             */
/*   Updated: 2023/03/07 17:13:01 by mravera          ###   ########.fr       */
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
