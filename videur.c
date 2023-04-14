/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   videur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:53:17 by mravera           #+#    #+#             */
/*   Updated: 2023/04/14 13:05:25 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	videur(char **buf, t_data *data)
{
	if (is_nsewkey(buf[0]) || is_fckey(buf[0]))
	{
		if (buf[1] == NULL)
			printf("\n[%s]\nError\nNo path provided.\n", buf[0]);
		else if (is_nsewkey(buf[0]))
			sort_nsew(buf, data);
		else if (is_fckey(buf[0]))
			sort_fc(buf, data);
	}
	else
		printf("\n[%s]\nError\nUnknown key.\n", buf[0]);
	return (0);
}

int	sort_nsew(char **str, t_data *data)
{
	if (!is_nsewkey(str[0]))
	{
		printf("Error\n666 sort_nsew()\n");
		return (1);
	}
	if (check_xpm(str) && !alrdy_set(str, data))
	{
		if (!ft_strncmp(str[0], "N", 2) || !ft_strncmp(str[0], "NO", 3))
			data->no = ft_strdup(str[1]);
		if (!ft_strncmp(str[0], "S", 2) || !ft_strncmp(str[0], "SO", 3))
			data->so = ft_strdup(str[1]);
		if (!ft_strncmp(str[0], "E", 2) || !ft_strncmp(str[0], "EA", 3))
			data->ea = ft_strdup(str[1]);
		if (!ft_strncmp(str[0], "W", 2) || !ft_strncmp(str[0], "WE", 3))
			data->we = ft_strdup(str[1]);
		printf("[%s->%s] OK\n", str[0], str[1]);
	}
	return (0);
}

int	sort_fc(char **str, t_data *data)
{
	if (!is_fckey(str[0]))
	{
		printf("\nError\n666 sort_fc()\n");
		return (1);
	}
	if (check_rgb(str))
	{
		if (!ft_strncmp(str[0], "F", 2))
			data->f_color = str_color(str[1]);
		if (!ft_strncmp(str[0], "C", 2))
			data->c_color = str_color(str[1]);
		printf("\n[%s->%s] OK\n", str[0], str[1]);
	}
	return (0);
}

int	check_xpm(char **path)
{
	int	i;
	int	fd;

	i = ft_strlen(path[1]);
	if (i < 5)
		return (!printf("\n[%s->%s]\nError\nPath too short to be valid.\n",
				path[0], path[1]));
	if (path[1][i - 1] == 'm' && path[1][i - 2] == 'p'
		&& path[1][i - 3] == 'x' && path[1][i - 4] == '.')
	{
		fd = open(path[1], O_RDONLY);
		if (fd < 0)
		{
			printf("\n[%s->%s]\n", path[0], path[1]);
			perror("Error\n");
			return (0);
		}
		return (!close(fd));
	}
	else
		printf("\n[%s->%s]\nError\nPath does not lead to a .xpm file.\n",
			path[0], path[1]);
	return (0);
}

int	check_rgb(char **str)
{
	char	**buf;
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	if (!str_isdigit(str[1]))
	{
		printf("\n[%s->%s]\nUnknown charracter in rgb code.\n", str[0], str[1]);
		return (0);
	}
	buf = ft_split(str[1], ',');
	while (buf[i] != NULL)
		i++;
	if (i != 3 || ft_atoi(buf[0]) < 0 || ft_atoi(buf[0]) > 255
		|| ft_atoi(buf[1]) < 0 || ft_atoi(buf[1]) > 255
		|| ft_atoi(buf[2]) < 0 || ft_atoi(buf[2]) > 255)
	{
		printf("\n[%s->%s]\nInvalid RGB code.\n", str[0], str[1]);
		freetab(buf);
		return (0);
	}
	freetab(buf);
	return (1);
}
