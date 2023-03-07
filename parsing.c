/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:04:08 by mravera           #+#    #+#             */
/*   Updated: 2023/03/07 14:32:52 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "parsing.h"

int	parsing(int argc, char **argv)
{
	t_data	data;
	int		fd;
	int		i;

	i = 0;
	data = (t_data){0};
	fd = check_cub(argc, argv);
	parse(fd, &data);
	check_close(fd);
	printf("no = %s\n", data.no);
	printf("so = %s\n", data.so);
	printf("ea = %s\n", data.ea);
	printf("we = %s\n", data.we);
	printf("c = %s\n", data.c);
	printf("f = %s\n", data.f);
	while (data.map[i])
		printf("%s\n", data.map[i ++]);
	free_data(&data);
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
		cub_printmap(buf);
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

int	cub_printmap(char *str)
{
	printf("Error\nMap not at the end of file.\n");
	free(str);
	return (0);
}
