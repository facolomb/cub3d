/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   videur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:53:17 by mravera           #+#    #+#             */
/*   Updated: 2023/02/23 15:39:17 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	videur(char **buf, t_data *data)
{
	int		i;

	i = 0;
	if (is_key(buf[0]))
	{
		if (buf[1] != NULL)
			sort_nsew(buf, data);
		printf("\n[%s]\nError\nNo path provided.\n", buf[0]);
	}
	else
		printf("\n[%s]\nError\nUnknown key.\n", buf[0]);
	return (0);
}

int	sort_nsew(char **str, t_data *data)
{
	if (!ft_strncmp(str[0], "N", 2) || !ft_strncmp(str[0], "NO", 3))
	{
		if (check_xpm(str[1]))
			data->no = ft_strdup(str[1]);
	}
	else if (!ft_strncmp(str[0], "S", 2) || !ft_strncmp(str[0], "SO", 3))
	{
		if (check_xpm(str[1]))
			data->so = ft_strdup(str[1]);
	}
	else if (!ft_strncmp(str[0], "E", 2) || !ft_strncmp(str[0], "EA", 3))
	{
		if (check_xpm(str[1]))
			data->ea = ft_strdup(str[1]);
	}
	else if (!ft_strncmp(str[0], "W", 2) || !ft_strncmp(str[0], "WE", 3))
	{
		if (check_xpm(str[1]))
			data->we = ft_strdup(str[1]);
	}
	else
		printf("FATAL ERROR\n");
	return (0);
}

int	check_xpm(char *path)
{
	int	i;
	int	fd;

	i = ft_strlen(path);
	if (i < 5)
	{
		printf("\n[%s]\nError\nPath too short to be valid.\n\n", path);
		return (0);
	}
	if (path[i - 1] == 'm' && path[i - 2] == 'p'
		&& path[i - 3] == 'x' && path[i - 4] == '.')
	{
		fd = open(path, O_RDONLY);
		if (fd < 0)
		{
			printf("\n[%s]\n", path);
			perror("Error\n");
			return (0);
		}
		return (!close(fd));
	}
	else
		printf("\n[%s]\nError\nPath does not lead to a .xpm file.\n\n", path);
	return (0);
}
