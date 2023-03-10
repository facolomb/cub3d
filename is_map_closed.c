/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:04:31 by mravera           #+#    #+#             */
/*   Updated: 2023/03/10 18:24:18 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	is_map_closed(t_data *data)
{
	char	**m;
	int		i;

	m = data->map;
	i = 0;
	return (1);
	return (0);
}

int	square_map(t_data *data)
{
	int		i;
	int		x;
	char	*buf;

	i = 0;
	x = ft_tabmaxlen(data->map);
	while (x && data->map[i])
	{
		if (ft_strlen(data->map[i]) < (size_t)x)
		{
			buf = stradd(data->map[i], x, '*');
			free(data->map[i]);
			data->map[i] = buf;
		}
		i++;
	}
	return (i);
}

int	ft_tabmaxlen(char **tab)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
			j++;
		if (j > x)
			x = j;
		j = 0;
		i++;
	}
	return (x);
}

char	*stradd(char *old, int size, char x)
{
	int		i;
	char	*res;

	if (!old || (ft_strlen(old) < (size_t)size))
	{
		res = malloc(sizeof(char) * (size + 1));
		i = ft_strlcpy(res, old, ft_strlen(old) + 1);
		while (i < size)
		{
			res[i] = x;
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
