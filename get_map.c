/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 00:22:26 by mravera           #+#    #+#             */
/*   Updated: 2023/03/07 14:32:20 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	get_map(char *buf, int fd, t_data *data)
{
	(void)fd;
	if (is_map(buf))
		data->map = add_line(data->map, buf);
	return (0);
}

char	**add_line(char **old, char *newline)
{
	int		i;
	char	**res;

	i = 0;
	while (old && old[i])
		i++;
	res = malloc((i + 2) * sizeof(char *));
	res[i + 1] = 0;
	i = 0;
	while (old && old[i])
	{
		res[i] = ft_strdup(old[i]);
		i ++;
	}
	res[i] = rm_lastbsn(newline);
	i = 0;
	if (old)
		freetab(old);
	return (res);
}
