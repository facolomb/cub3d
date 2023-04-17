/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:04:08 by mravera           #+#    #+#             */
/*   Updated: 2023/04/15 05:17:16 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing(int argc, char **argv, t_data *data)
{
	int		fd;

	fd = check_cub(argc, argv);
	parse(fd, data);
	check_close(fd);
	printf("\nChecking the map.\n");
	if (data->map != NULL)
		check_map(data);
	else
	{
		printf("Error\nNo map detected.\n");
		data->dead = 1;
	}
	return (0);
}

int	parse(int fd, t_data *data)
{
	char	*buf;
	char	**treuse;

	buf = get_next_line(fd);
	while (buf != NULL && !is_map(buf))
	{
		if (is_line(buf))
		{
			treuse = get_clean_buf(buf);
			videur(treuse, data);
			freetab(treuse);
		}
		free(buf);
		buf = get_next_line(fd);
	}
	while (buf != NULL && is_map(buf))
	{
		get_map(buf, fd, data);
		free(buf);
		buf = get_next_line(fd);
	}
	if (buf != NULL && !is_map(buf))
		cub_printmap(buf, data);
	return (0);
}

int	is_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] == ' ')
		i ++;
	if (line[i] && line[i] != '\n')
		return (1);
	else
		return (0);
}

int	cub_printmap(char *str, t_data *data)
{
	printf("Error\nMap not at the end of file.\n");
	data->dead = 1;
	free(str);
	return (0);
}
