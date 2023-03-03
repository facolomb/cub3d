/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:30:27 by mravera           #+#    #+#             */
/*   Updated: 2023/03/03 18:05:15 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	is_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '1')
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
