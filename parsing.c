/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:04:08 by mravera           #+#    #+#             */
/*   Updated: 2023/02/23 15:36:23 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	parsing(int argc, char **argv)
{
	t_data	data;
	int		fd;

	data = (t_data){0};
	fd = check_cub(argc, argv);
	parse(fd, &data);
	check_close(fd);
	return (0);
}

int	parse(int fd, t_data *data)
{
	char	**buf;
	int		i;

	i = 0;
	buf = get_clean_buf(fd);
	printf("%i. buf = %s\n", i, buf[0]);
	while (buf[0] != NULL && !is_map(buf[0]))
	{
		videur(buf, data);
		freetab(buf);
		buf = get_clean_buf(fd);
		i++;
		printf("%i. buf = %s\n", i, buf[0]);
	}
	printf("\nfinal data->no = ||%s||\n", data->no);
	printf("final data->so = ||%s||\n", data->so);
	printf("final data->ea = ||%s||\n", data->ea);
	printf("final data->we = ||%s||\n", data->we);
	return (0);
}

int	is_nsewcf(char *str)
{
	if (!ft_strncmp(str, "N", 1) || !ft_strncmp(str, "S", 1)
		|| !ft_strncmp(str, "E", 1) || !ft_strncmp(str, "W", 1)
		|| !ft_strncmp(str, "F", 1) || !ft_strncmp(str, "C", 1))
		return (1);
	else
		return (0);
}

int	is_map(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] == ' ')
		i++;
	if (str[i++] == '1')
		n ++;
	while (str[i] == ' ' || str[i] == '1')
		i ++;
	if (n == 0)
		return (0);
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	is_key(char *str)
{
	if (!ft_strncmp(str, "N", 2) || !ft_strncmp(str, "NO", 3)
		|| !ft_strncmp(str, "E", 2) || !ft_strncmp(str, "EA", 3)
		|| !ft_strncmp(str, "W", 2) || !ft_strncmp(str, "WE", 3)
		|| !ft_strncmp(str, "C", 2) || !ft_strncmp(str, "F", 2))
		return (1);
	return (0);
}
